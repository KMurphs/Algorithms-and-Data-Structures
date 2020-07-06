#include <bits/stdc++.h>

using namespace std;


// 1. Brute Force
// 2. Memoization
// 3. Tabulation

// Brute Force
// Brute Force Solution is formulated in a recursive form (optimal substructure property)
// Same subsproblems are solved again and again (although number of possible games is O(2^n))
// There are only (n-1) games of size 2 (overlapping subproblems)
// We therefore have a good candidate for dynamic programming
void solve(int *set, int setSize, int *pMoves, int l, int r, int pId, int *localSol){

  if(l > r){
    localSol[0] = 0;
    localSol[1] = 0;
    return;
  }


  int *lSol = new int[2]{0, 0};
  int *rSol = new int[2]{0, 0};


  int *lMoves = new int[setSize];
  memset(lMoves, 0, sizeof(int) * setSize);
  lMoves[l] = pId;
  solve(set, setSize, lMoves, l + 1, r, pId + 1, lSol);


  int *rMoves = new int[setSize];
  memset(rMoves, 0, sizeof(int) * setSize);
  rMoves[r] = pId;
  solve(set, setSize, rMoves, l, r - 1, pId + 1, rSol);


  int lSum = set[l] + lSol[pId % 2];
  int rSum = set[r] + rSol[pId % 2];
  localSol[0 + (pId % 2)] = max(lSum, rSum);
  localSol[1 - (pId % 2)] = lSum > rSum ? lSol[1 - (pId % 2)] : rSol[1 - (pId % 2)];


  copy(
    (lSum > rSum ? lMoves : rMoves) + l, 
    (lSum > rSum ? lMoves : rMoves) + r + 1, 
    pMoves + l
  );
}

void printSolution(int *set, int *pMoves, int setSize, int l, int r, int pCurrSum, int pAltSum){

  if(l > r) return;

  int cMove = min(pMoves[l], pMoves[r]);
  int pCurrMove;

  if(pMoves[l] == cMove) pCurrMove = set[l++];
  else if(pMoves[r] == cMove) pCurrMove = set[r--];

  cout << "Player '" << (1 + (cMove % 2)) << "' chose : '" << pCurrMove << "'. Current Sum ('" << (pCurrSum + pCurrMove) << "')" << endl;

  printSolution(set, pMoves, setSize, l, r, pAltSum, pCurrSum + pCurrMove);
}

int findOptimalStrategy(int *set, int setSize){
  int *glSol = new int[2]{ 0, 0 };
  int *pMoves = new int[setSize];
  memset(pMoves, 0, sizeof(int) * setSize);

  solve(set, setSize, pMoves, 0, setSize - 1, 0, glSol);

  cout << "              ******" << endl;
  printSolution(set, pMoves, setSize, 0, setSize - 1, 0, 0);
  return glSol[0];
}




struct TDPItem{
  int pSums[2];
  int pCurrMove;
  int pCurrPlayer;
};

// We will first solve problems of size 2, then 3, ... until the whole problem is solved
int findOptimalStrategyDP(int *set, int setSize){

  TDPItem **dp = new TDPItem*[setSize];
  for(int i = 0 ; i < setSize ; i++){
    dp[i] = new TDPItem[setSize];
    memset(dp[i], 0, setSize * sizeof(TDPItem));
  }


  for(int i = 0 ; i < setSize ; i++){
    dp[i][i].pCurrPlayer = 1;
    dp[i][i].pCurrMove = set[i];
    dp[i][i].pSums[0] = 0;
    dp[i][i].pSums[1] = set[i];
  }


  for(int gSize = 1 ; gSize < setSize ; gSize++){
    for(int l = 0, r = l + gSize ; l < setSize && r < setSize ; l++, r = l + gSize){

      int pCurr = (r - l + 1) % 2;
      int pNext = 1 - pCurr;

      dp[l][r].pCurrPlayer = pCurr;



      int lMove = set[l] + dp[l + 1][r].pSums[pCurr];
      int rMove = set[r] + dp[l][r - 1].pSums[pCurr];

      dp[l][r].pCurrMove = lMove > rMove ? set[l] : set[r];



      dp[l][r].pSums[pCurr] = lMove > rMove ? lMove : rMove;
      dp[l][r].pSums[pNext] = lMove > rMove 
            ? dp[l + 1][r].pSums[pNext]
            : dp[l][r - 1].pSums[pNext];
    }
  }

  return dp[0][setSize - 1].pSums[0];
}






// https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
int main(int argc, char **argv, char **envp){

  int *set, setSize;

  setSize = 4, set = new int[setSize]{ 8, 15, 3, 7 };
  assert(findOptimalStrategy(set, setSize) == 22);
  assert(findOptimalStrategyDP(set, setSize) == 22);

  setSize = 4, set = new int[setSize]{ 5, 3, 7, 10 };
  assert(findOptimalStrategy(set, setSize) == 15);
  assert(findOptimalStrategyDP(set, setSize) == 15);

  setSize = 4, set = new int[setSize]{ 2, 2, 2, 2 };
  assert(findOptimalStrategy(set, setSize) == 4);
  assert(findOptimalStrategyDP(set, setSize) == 4);

  setSize = 6, set = new int[setSize]{ 20, 30, 2, 2, 2, 10 };
  assert(findOptimalStrategy(set, setSize) == 42);
  assert(findOptimalStrategyDP(set, setSize) == 42);





  cout << "\nProgram Exited successfully";
  return 0;
}
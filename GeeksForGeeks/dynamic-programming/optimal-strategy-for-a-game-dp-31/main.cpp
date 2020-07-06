#include <bits/stdc++.h>

using namespace std;




//Brute Force
void solve(int *set, int setSize, int *pMoves, int l, int r, int pId, int *localSol){

  if(l > r){
    localSol[0] = 0;
    localSol[1] = 0;
    return;
  }

  int *lSol = new int[2]{0, 0};
  int *rSol = new int[2]{0, 0};

  pMoves[l] = pId % 2;
  solve(set, setSize, pMoves, l + 1, r, pId + 1, lSol);

  pMoves[r] = pId % 2;
  solve(set, setSize, pMoves, l, r - 1, pId + 1, rSol);

  int lSum = set[l] + lSol[pId % 2];
  int rSum = set[r] + rSol[pId % 2];
  localSol[0 + (pId % 2)] = max(lSum, rSum);
  localSol[1 - (pId % 2)] = lSum > rSum ? lSol[1 - (pId % 2)] : rSol[1 - (pId % 2)];

}



void printSolution(int *set, int *pMoves, int setSize, int l, int r, int pId, int pCurrSum, int pAltSum){

  if(l > r) return;

  int pCurrMove;
  if(pMoves[l] == (pId % 2)) pCurrMove = set[l++];
  else if(pMoves[r] == (pId % 2)) pCurrMove = set[r--];

  cout << "Player '" << (1 + pId % 2) << "' chose : '" << pCurrMove << "'. Current Sum ('" << (pCurrSum + pCurrMove) << "')" << endl;

  printSolution(set, pMoves, setSize, l, r, pId + 1, pAltSum, pCurrSum + pCurrMove);
}




int findOptimalStrategy(int *set, int setSize){
  int *glSol = new int[2]{ 0, 0 };
  int *pMoves = new int[setSize];
  memset(pMoves, 0, sizeof(int) * setSize);

  solve(set, setSize, pMoves, 0, setSize - 1, 0, glSol);

  cout << "              ******" << endl;
  printSolution(set, pMoves, setSize, 0, setSize - 1, 0, 0, 0);
  return glSol[0];
}






// https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
int main(int argc, char **argv, char **envp){

  int *set, setSize;

  setSize = 4, set = new int[setSize]{ 8, 15, 3, 7 };
  assert(findOptimalStrategy(set, setSize) == 22);

  setSize = 4, set = new int[setSize]{ 5, 3, 7, 10 };
  assert(findOptimalStrategy(set, setSize) == 15);

  setSize = 4, set = new int[setSize]{ 2, 2, 2, 2 };
  assert(findOptimalStrategy(set, setSize) == 4);

  setSize = 6, set = new int[setSize]{ 20, 30, 2, 2, 2, 10 };
  assert(findOptimalStrategy(set, setSize) == 42);





  cout << "\nProgram Exited successfully";
  return 0;
}
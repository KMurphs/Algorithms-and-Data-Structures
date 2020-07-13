#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// 1. combinatorial solution
// 2. recursive brute force
// 3. contained recursive state
// 4. overlapping subproblems
// 5. ordering on dimensions (start and pos)
// Note: exponential brute force => O(2^n)

int countDiceThrowsUtil(int n, int m, int target, int curr, int nDice, string choices){

  if(nDice == n + 1 && curr == target) cout << choices << endl;
  if(nDice == n + 1 && curr == target) return 1;
  
  
  // if(curr >= target) cout << "\t" << choices << endl;
  if(curr >= target) return 0;
  // if(nDice >= n + 1) cout << "\t\t" << choices << endl;;
  if(nDice >= n + 1) return 0;


  int count = 0;
  for (int i = 1; i <= m; i++){
    count += countDiceThrowsUtil(n, m, target, curr + i, nDice + 1, choices + to_string(i) + ", ");
  }
  return count;
}



int countDiceThrowsUtil2(int n, int m, int target){

  if(target <= 0){
    return 0;
  }
  if(n == 1){
    if(target <= m) return 1;
    else return 0;
  }


  int count = 0;
  for(int i = 1 ; i <= m ; i++ ){
    count += countDiceThrowsUtil2(n - 1, m, target - i);
  }
  return count;
}

int countDiceThrows(int n, int m, int target){
  // return countDiceThrowsUtil(n, m, target, 0, 1, "");
  return countDiceThrowsUtil2(n, m, target);
}







int countDiceThrowsDP(int n, int m, int target){

  int **dp = new int*[n + 1];
  for(int i = 0 ; i < n + 1 ; i++){
    dp[i] = new int[target + 1];
    memset(dp[i], 0, sizeof(int) * (target + 1));
  }
  

  for(int k = 1 ; k <= m && k <= target ; k++){
    dp[1][k] = 1;
  }

  for(int i = 2 ; i <= n ; i++){
    for(int j = 1 ; j <= target ; j++){

      for(int k = 1 ; k <= m ; k++){
        if(j - k < 0) continue;
        dp[i][j] += dp[i - 1][j - k];
      }

    }
  }

  // string res = printSolution(dp, n);
  // cout << res << endl;

  return dp[n][target];
}





// https://www.geeksforgeeks.org/dice-throw-dp-30/
int main(){

    int n, m, target, exp;

    n = 2, m = 4, target = 1, exp = 0;
    assert(countDiceThrows(n, m, target) == exp);
    assert(countDiceThrowsDP(n, m, target) == exp);


    n = 2, m = 2, target = 3, exp = 2;
    assert(countDiceThrows(n, m, target) == exp);
    assert(countDiceThrowsDP(n, m, target) == exp);


    n = 3, m = 6, target = 8, exp = 21;
    assert(countDiceThrows(n, m, target) == exp);
    assert(countDiceThrowsDP(n, m, target) == exp);


    n = 2, m = 4, target = 5, exp = 4;
    assert(countDiceThrows(n, m, target) == exp);
    assert(countDiceThrowsDP(n, m, target) == exp);


    n = 3, m = 4, target = 5, exp = 6;
    assert(countDiceThrows(n, m, target) == exp);
    assert(countDiceThrowsDP(n, m, target) == exp);


    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
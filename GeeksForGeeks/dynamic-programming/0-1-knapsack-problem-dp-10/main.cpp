#include <bits/stdc++.h>

using namespace std;



// Here also optimization problem, optimal substructure (recursive combinatorial brute force), overlapping subproblems
// subproblems however do not lend themselves naturally to bottom up dp paradigm 
int solveKnapsackUtil(int *weights, int *values, int n, int maxWeight, int start, int currValue, int currWeight){

  if(currWeight > maxWeight){
    return INT_MIN;
  }
  if(start >= n){
    return currValue;
  }


  return max(
    solveKnapsackUtil(weights, values, n, maxWeight, start + 1, currValue, currWeight),
    solveKnapsackUtil(weights, values, n, maxWeight, start + 1, currValue + values[start], currWeight + weights[start])
  );
}


int solveKnapsack(int *weights, int *values, int n, int maxWeight){
  return solveKnapsackUtil(weights, values, n, maxWeight, 0, 0, 0);
}












void printSolution(int **dp, int *values, int *weights, int row, int col){

  if(row == 0){
    cout << endl;
    return;
  }


  if(dp[row - 1][col] != dp[row][col] && col >= weights[row - 1]){
    cout << "Value: " << values[row - 1] << " - Weight: " << weights[row - 1] << endl;
  }


  if(dp[row - 1][col] == dp[row][col] ){
    printSolution(dp, values, weights, row - 1, col);
  }else if(col >= weights[row - 1]){
    printSolution(dp, values, weights, row - 1, col - weights[row - 1]);
  }

}


int solveKnapsackDP(int *weights, int *values, int n, int maxWeight){


  int **dp = new int*[n + 1];
  for (int i = 0; i < n + 1; i++){
    dp[i] = new int[maxWeight + 1];
    memset(dp[i], 0, sizeof(int) * (maxWeight + 1));
  }



  for (int j = 1; j < maxWeight + 1; j++) {
    dp[0][j] = INT_MIN;
  }

  for (int i = 1; i < n + 1; i++) {
    dp[i][0] = 0;

    for (int j = 1; j < maxWeight + 1; j++) {
      dp[i][j] = dp[i - 1][j];

      if((j >= weights[i - 1]) && dp[i][j] < dp[i - 1][j - weights[i - 1]]){
        dp[i][j] = dp[i - 1][j - weights[i - 1]] + values[i - 1];
      }

    }
  }
  

  int maxVal = 0, maxWght = 0;
  for (int j = maxWeight; j >= 0; j--){
    if (dp[n][j] != INT_MIN) {
      maxVal = dp[n][j];
      maxWght = j;
      break;
    }
  }


  printSolution(dp, values, weights, n, maxWght);


  return maxVal;
}








// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
int main(int argc, char **argv, char **envp){

  int n, *wgts, *vals, maxW, exp;


  n = 3, wgts = new int[n]{10, 20, 30}, vals = new int[n]{60, 100, 120}, maxW = 50, exp = 220;
  assert(solveKnapsack(wgts, vals, n, maxW) == exp);
  assert(solveKnapsackDP(wgts, vals, n, maxW) == exp);


  cout << "\nProgram Exited successfully";
  return 0;
}
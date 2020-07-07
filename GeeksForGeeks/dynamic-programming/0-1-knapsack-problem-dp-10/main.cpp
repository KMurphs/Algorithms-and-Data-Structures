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












void printSolution(int **dp, int *values, int row, int col, int maxWeight){

  if(row == 0){
    cout << endl;
    return;
  }

  if(!dp[row - 1][col] <= maxWeight && col >= values[row - 1]){
    cout << values[row - 1] << "  ";
  }

  if(dp[row - 1][col] <= maxWeight){
    printSolution(dp, values, row - 1, col, maxWeight);
  }else if(col >= values[row - 1]){
    printSolution(dp, values, row - 1, col - values[row - 1], maxWeight);
  }

}


int solveKnapsackDP(int *weights, int *values, int n, int maxWeight){

  int sumValues = accumulate(values, values + n, 0);

  int **dp = new int*[n + 1];
  for (int i = 0; i < n + 1; i++){
    dp[i] = new int[sumValues + 1];
    memset(dp[i], 0, sizeof(int) * (sumValues + 1));
  }
  
  for (int j = 1; j < sumValues + 1; j++) {
    dp[0][j] = INT_MAX;
  }

  for (int i = 1; i < n + 1; i++) {

    dp[i][0] = 0;

    for (int j = 1; j < sumValues + 1; j++) {


      int wght1 = dp[i - 1][j];


      int wght2 = ( (j >= values[i - 1]) && (dp[i - 1][j - values[i - 1]] <= maxWeight) )
        ? dp[i - 1][j - values[i - 1]] + weights[i - 1]
        : INT_MAX;


      int wght3 = max(wght1, wght2);
      if(wght1 > maxWeight || wght2 > maxWeight) wght3 = min(wght1, wght2);


      dp[i][j] = wght3 > maxWeight ? INT_MAX : wght3;

    }
  }
  

  int maxValue = 0;
  for (int j = sumValues; j >= 0; j--){
    if (dp[n][j] <= maxWeight) {
      maxValue = j;
      break;
    }
  }


  printSolution(dp, values, n, maxValue, maxWeight);


  return maxValue;
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
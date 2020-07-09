#include <bits/stdc++.h>

using namespace std;


struct TSolution{
  int rows, cols, ops;
  TSolution(): rows(0), cols(0), ops(0){}
};
// combinatorial exercise
// recursive brute force approach (optimal substructure)
// overlapping subproblems (the same 3 consecutive elemnts are reused 
// all over the palce)
TSolution solve(int *mats, int n, int start, int end){

  TSolution res = *new TSolution();
  if(end - start == 1){
    res.rows = mats[start];
    res.cols = mats[end];
    return res;
  }

  
  int tmp;
  res.ops = INT_MAX;
  for(int i = start + 1 ; i < end ; i++){

    TSolution r1 = solve(mats, n, start, i);
    TSolution r2 = solve(mats, n, i, end);

    tmp = r1.ops + r2.ops + (r1.rows * r2.rows * r2.cols);
    if(tmp < res.ops){
      res.rows = r1.rows;
      res.cols = r2.cols;
      res.ops = tmp;
    }

  }

  return res;
}

int reduceTotalOperations(int *mats, int n){
  TSolution res = solve(mats, n, 0, n - 1);
  return res.ops;
}










string printSolution(int **dp, int *mats, int row, int col){

  if(col - row == 1){
    return *new string(1, (char)('A' + row));
  }

  int ops;
  
  ops = dp[row][col - 1] + mats[row] * mats[col - 1] * mats[col];

  if(dp[row][col] == ops){
    string res = printSolution(dp, mats, row, col - 1);
    return (res.size() > 1 ? "(" + res + ")" : res) + "*" + (char)('A' + col - 1);
  }

  string res = printSolution(dp, mats, row + 1, col);
  return *new string(1, (char)('A' + row)) + "*" + (res.size() > 1 ? "(" + res + ")" : res);
}

int reduceTotalOperationsDP(int *mats, int n){


  int **dp = new int*[n];
  for (int i = 0; i < n; i++){
    dp[i] = new int[n];
    memset(dp[i], 0, sizeof(int) * n);
  }
  

  for (int i = 0; i < n; i++){
    dp[i][i] = 0;
  }
  for (int i = 0; i < n - 1; i++){
    dp[i][i + 1] = 0;
  }


  for (int l = 2; l < n; l++){
    for (int i = 0; i < n && i + l < n; i++){
      dp[i][i + l] = min(
        dp[i][i + l - 1] + mats[i] * mats[i + l - 1] * mats[i + l],
        dp[i + 1][i + l] + mats[i + 1] * mats[i] * mats[i + l]
      );
    }
  }

  string res = printSolution(dp, mats, 0, n - 1);
  cout << res << endl;


  return dp[0][n - 1];
}




// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
int main(int argc, char **argv, char **envp){

  int *mats, n, exp;



  n = 5, mats = new int[n]{ 40, 20, 30, 10, 30 }, exp = 26000;
  cout << reduceTotalOperations(mats, n) << endl;
  assert(reduceTotalOperations(mats, n) == exp);
  assert(reduceTotalOperationsDP(mats, n) == exp);


  n = 5, mats = new int[n]{ 10, 20, 30, 40, 30 }, exp = 30000;
  cout << reduceTotalOperations(mats, n) << endl;
  assert(reduceTotalOperations(mats, n) == exp);
  assert(reduceTotalOperationsDP(mats, n) == exp);


  n = 3, mats = new int[n]{ 10, 20, 30 }, exp = 6000;
  cout << reduceTotalOperations(mats, n) << endl;
  assert(reduceTotalOperations(mats, n) == exp);
  assert(reduceTotalOperationsDP(mats, n) == exp);



  cout << "\nProgram Exited successfully";
  return 0;
}
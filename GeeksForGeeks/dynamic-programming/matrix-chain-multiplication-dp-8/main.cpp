#include <bits/stdc++.h>

using namespace std;


struct TSolution{
  int rows, cols, ops;
  TSolution(): rows(0), cols(0), ops(0){}
};

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


// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
int main(int argc, char **argv, char **envp){

  int *mats, n, exp;



  n = 5, mats = new int[n]{ 40, 20, 30, 10, 30 }, exp = 26000;
  cout << reduceTotalOperations(mats, n) << endl;
  assert(reduceTotalOperations(mats, n) == exp);


  n = 5, mats = new int[n]{ 10, 20, 30, 40, 30 }, exp = 30000;
  cout << reduceTotalOperations(mats, n) << endl;
  assert(reduceTotalOperations(mats, n) == exp);


  n = 3, mats = new int[n]{ 10, 20, 30 }, exp = 6000;
  cout << reduceTotalOperations(mats, n) << endl;
  assert(reduceTotalOperations(mats, n) == exp);



  cout << "\nProgram Exited successfully";
  return 0;
}
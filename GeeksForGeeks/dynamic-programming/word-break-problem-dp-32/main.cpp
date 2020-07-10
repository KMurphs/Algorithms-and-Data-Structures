#include <bits/stdc++.h>
using namespace std;



int countChangesUtil(int *changes, int n, int currAmount, int pos){

  if(currAmount == 0) return 1;
  if(currAmount <  0) return 0;
  if(pos >= n) return 0;

  int arrs = 0;
  for (int i = pos; i < n; i++){
    arrs += countChangesUtil(changes, n, currAmount - changes[i], i);
  }
  return arrs;
}

int countChanges(int *changes, int n, int amount){
  return countChangesUtil(changes, n, amount, 0);
}












vector<string> printSolution(pair<int, int> **dp, int *changes, int row, int col, string curr){

  vector<string> res = *new vector<string>();

  if(row == 0){
    res.push_back(curr);
    return res;
  }

  if(col == 0){
    res.push_back(curr);
    return res;
  }

  if(row == col){
    // res.push_back(to_string(changes[row - 1]) + ", " + curr);
    // cout << changes[row - 1] << ", " << curr << endl;
  }
  
  if(dp[row][col].first != 0){
    vector<string> r1 = printSolution(dp, changes, row - 1, col, curr);
    for(vector<string>::iterator i = r1.begin() ; i != r1.end() ; ++i)
      res.push_back(*i);
  }

  if(dp[row][col].second != 0){
    vector<string> r2 = printSolution(dp, changes, row, col - changes[row - 1], to_string(changes[row - 1]) + ", " + curr);
    for(vector<string>::iterator i = r2.begin() ; i != r2.end() ; ++i)
      res.push_back(*i);
  }


  return res;
}



int countChangesDP(int *changes, int n, int amount){

  sort(changes, changes + n);

  pair<int, int> **dp = new pair<int, int>*[n + 1];
  for(int i = 0 ; i < n + 1 ; i++){
    dp[i] = new pair<int, int>[amount + 1];
    memset(dp[i], 0 , sizeof(pair<int, int>) * (amount + 1));
  }

  for(int i = 1 ; i < n + 1 ; i++){
    dp[i][0].first = 1;
    dp[i][0].second = 0;
  }

  for(int i = 1 ; i < n + 1 ; i++){
    for(int j = 1 ; j < amount + 1 ; j++){

      dp[i][j].first = dp[i - 1][j].first + dp[i - 1][j].second;
      
      if(j >= changes[i - 1])
        dp[i][j].second = dp[i][j - changes[i - 1]].first + dp[i][j - changes[i - 1]].second;

    }
  }


  vector<string> res = printSolution(dp, changes, n, amount, "");
  for(vector<string>::iterator i = res.begin() ; i != res.end() ; ++i)
    cout << *i << endl;

  return dp[n][amount].first + dp[n][amount].second;
}













// https://www.geeksforgeeks.org/coin-change-dp-7/
int main(){

    int n, *change, amount, exp;

    amount = 4, n = 3, change = new int[n]{ 1, 2, 3 }, exp = 4;
    assert(countChanges(change, n, amount) == exp);
    assert(countChangesDP(change, n, amount) == exp);

    amount = 10, n = 4, change = new int[n]{ 2, 5, 3, 6 }, exp = 5;
    assert(countChanges(change, n, amount) == exp);
    assert(countChangesDP(change, n, amount) == exp);


    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
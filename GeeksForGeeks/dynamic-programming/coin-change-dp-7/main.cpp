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












string printSolution(int *dp, int currLength){

  if(currLength == 0){
    return "";
  }


  int l = 1, r = currLength - 1;
  bool found = false;
  while(l <= r){
    if(dp[currLength] == dp[l] + dp[r]){
      found = true;
      break;
    }
    l++, r--;
  }

  if(!found){
    return to_string(currLength);
  }

  return printSolution(dp, l) + ", " + printSolution(dp, r);
}


// O(n^2)
// n entries in dp, each entry is calculated by considering all the entries below it
int countChangesDP(int *changes, int n, int amount){

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


  // string res = printSolution(dp, rodLength);
  // cout << res << endl;

  return dp[n][amount].first + dp[n][amount].second;
}













// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
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
#include <bits/stdc++.h>
using namespace std;


// Combinatorial Problem
// Recursive Combinatorial Solution (optimal substructure property - state is localized)
// Overlapping problems since any branch must generate and consider 
// the same solution for the all rods of length 3 for example
// O(n^n)
int maximizeCutsUtil(int *lengths, int *prices, int n, int currLength, int currPrice){

  if(currLength == 0) return currPrice;
  if(currLength <  0) return INT_MIN;

  int tmpPrice, maxPrice = INT_MIN;
  for (int i = 0; i < n; i++){

    tmpPrice = maximizeCutsUtil(lengths, prices, n, currLength - lengths[i], currPrice + prices[i]);

    if(tmpPrice > maxPrice){
      maxPrice = tmpPrice;
    }
  }

  return maxPrice;
}
int maximizeCuts(int *lengths, int *prices, int n, int rodLength){
  return maximizeCutsUtil(lengths, prices, n, rodLength, 0);
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
int maximizeCutsDP(int *lengths, int *prices, int n, int rodLength){

  int *dp = new int[rodLength + 1];
  memset(dp, 0, sizeof(int) * (rodLength + 1)); 

  for(int i = 0 ; i < n ; i++){
    dp[lengths[i]] = prices[i];
  }

  for(int i = 1 ; i < rodLength + 1 ; i++){

    int l = 0, r = i;
    while(l <= r){
      if(dp[i] < dp[l] + dp[r]){
        dp[i] = dp[l] + dp[r];
      }
      l++, r--;
    }

  }


  string res = printSolution(dp, rodLength);
  cout << res << endl;

  return dp[rodLength];
}













// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
int main(){

    int n, *lengths, *prices, rodLength, exp;

    rodLength = 8, n = 8, lengths = new int[n]{ 1, 2, 3, 4, 5, 6, 7, 8 }, prices = new int[n]{ 1, 5, 8, 9, 10, 17, 17, 20 }, exp = 22;
    assert(maximizeCuts(lengths, prices, n, rodLength) == exp);
    assert(maximizeCutsDP(lengths, prices, n, rodLength) == exp);

    rodLength = 8, n = 8, lengths = new int[n]{ 1, 2, 3, 4, 5, 6, 7, 8 }, prices = new int[n]{ 3, 5, 8, 9, 10, 17, 17, 20 }, exp = 24;
    assert(maximizeCuts(lengths, prices, n, rodLength) == exp);
    assert(maximizeCutsDP(lengths, prices, n, rodLength) == exp);


    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
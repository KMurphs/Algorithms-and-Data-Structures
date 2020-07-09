#include <bits/stdc++.h>
using namespace std;


// Optimization Problem
// Recursive Combinatorial Solution (optimal substructure property)
// Overlapping problems since any branch must generate and consider 
// the same solution for the last 3 elemts 
bool partitionUtil(int *arr, int n, int start, int sum1, int sum2){

  if(start >= n){
    return sum1 == sum2;
  }

  return partitionUtil(arr, n, start + 1, sum1, sum2 + arr[start])
      || partitionUtil(arr, n, start + 1, sum1 + arr[start], sum2);
}

bool partition(int *arr, int n){
  if(accumulate(arr, arr + n, 0) % 2 != 0)
    return false;
  return partitionUtil(arr, n, 0, 0, 0);
}












void printSolution(int **dp, int *arr, int row, int col){

  if(row == 0){
    cout << endl;
    return;
  }

  if(!dp[row - 1][col] && col >= arr[row - 1]){
    cout << "Set 1: " << arr[row - 1] << endl;
  }else{
    cout << "Set 2: " << arr[row - 1] << endl;
  }

  if(dp[row - 1][col]){
    printSolution(dp, arr, row - 1, col);
  }else if(col >= arr[row - 1]){
    printSolution(dp, arr, row - 1, col - arr[row - 1]);
  }

}

// Altough the overlapping would suggest solving subproblems of 
// increasing sizes. No recursive relation between these subproblems
// was found that can be used to build solution from the bottom up
// Instead, we will change the problem space to 
// array elmts, vs set of all possible sums of subset 1 
// The final solution will be borne out of the sum that is closest to
// the middle of the maximum sum
int partitionDP(int *arr, int n){


  const int sum = accumulate(arr, arr + n, 0);
  if(sum % 2 != 0)
    return false;

  const int hSum = sum / 2;

  int **dp = new int*[n + 1];
  for(int i = 0 ; i < n + 1; i++){
    dp[i] = new int[hSum + 1];
    memset(dp[i], 0, sizeof(int) * (hSum + 1)); 
  }


  // each cell will answer the question 
  // can we get to this sum using previous and possibly current arr elemt?
  for(int i = 1 ; i < n + 1 ; i++){
    dp[i][0] = 1;
    for (int j = 1; j < hSum + 1; j++){
      
      // first of all can we get to the current sum j
      // by using previous set? If that's the case
      // we don't need to include curr arr elemt
      dp[i][j] = dp[i - 1][j];

      if((dp[i][j] == 0) && (arr[i - 1] >= j)){
        // We can't get to surr sum j using previous set.
        // Can we alternatively get to currSum - currArrElemt?
        // using previous set. If this is possible, then
        // we can using previous set to get to (currSum - currArrElemt)
        // and include currArrELemt, and increase this sum from
        // (currSum - currArrElemt) to (currSum - currArrElemt + currArrElemt)
        dp[i][j] = dp[i - 1][j - arr[i - 1]];
      }
    }
  }





  if(dp[n][hSum] == 1){
    printSolution(dp, arr, n, hSum);
  }



  return dp[n][hSum];
}













// https://www.geeksforgeeks.org/partition-problem-dp-18/
int main(){

    int n, *arr;  
    bool exp;

    n = 4, arr = new int[n]{ 1, 6, 11, 5 }, exp = 0;
    assert(partition(arr, n) == exp);
    assert(partitionDP(arr, n) == exp);

    n = 4, arr = new int[n]{ 1, 5, 11, 5 }, exp = 1;
    assert(partition(arr, n) == exp);
    assert(partitionDP(arr, n) == exp);
    
    n = 4, arr = new int[n]{ 1, 5, 3 }, exp = 0;
    assert(partition(arr, n) == exp);
    assert(partitionDP(arr, n) == exp);


    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
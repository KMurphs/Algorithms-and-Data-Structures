#include <bits/stdc++.h>

using namespace std;



// Brute Force approach
// Notice how this screams NOT dynamic programming!?
// Brute force approach is recursive (optimal substructure) : so that's good
// For each branch generated just before the return statement
// it easy to find that the problems being solved do not overlap
// However, the O(2^n) time complexity here screams try something else
bool solve(int *set, int setSize, int target, int currPos, int currSum){
  if(currSum == target) return true;
  if(currPos >= setSize) return false;

  // We could also stop early, under the provision that numbers are always positive
  if(currSum > target) return false; 

  return solve(set, setSize, target, currPos + 1, currSum) 
      || solve(set, setSize, target, currPos + 1, currSum + set[currPos]);
}


bool findSubsetWithSum(int *set, int setSize, int target){
  return solve(set, setSize, target, 0, 0);
}




// We could change the problem space using sum as one dimension
// We are borrowing the notion of memoizer from dp, and trying to build that step by step from the bottom up
// This is not the textbook definition of what dp is
// Time complexity (n * target)
// Note that as long as target stays bounded (close to 0), we are good... otherwise the adequacy of doing this might be questionable
bool findSubsetWithSum2(int *set, int setSize, int target){
  // int sumTotal = accumulate(set, set + setSize, 0);

  bool **dp = new bool*[setSize + 1];
  for(int i = 0 ; i <= setSize ; i++){
    dp[i] = new bool[target + 1];
    memset(dp[i], 0, sizeof(bool) * (target + 1));
    dp[i][0] = 1;
  } 



  for(int i = 1 ; i < setSize + 1 ; i++){
    for(int j = 1 ; j < target + 1 ; j++){
      
      // Let's say we didn't use curr set element tp get to target
      // then we must find out whether we could get to target using
      // previous set elements
      dp[i][j] = dp[i - 1][j];

      // If we couldn't get to target using previous elements
      // Let's see whether we were able to get to
      // j (aka current sum being considered) - curr set element
      // If we could, then using curr set element will allow us to reach curr sum (j)
      if((dp[i][j] == 0) && (set[i - 1] <= j)){
        dp[i][j] = dp[i - 1][j - set[i - 1]];
      }
    }
  }


  return dp[setSize][target];
}








// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
int main(int argc, char **argv, char **envp){

  int *set, sum, setSize;

  setSize = 6, set = new int[setSize]{3, 34, 4, 12, 5, 2}, sum = 9;
  assert(findSubsetWithSum(set, setSize, sum));
  assert(findSubsetWithSum2(set, setSize, sum));

  setSize = 6, set = new int[setSize]{3, 34, 4, 12, 5, 2}, sum = 30;
  assert(!findSubsetWithSum(set, setSize, sum));
  assert(!findSubsetWithSum2(set, setSize, sum));



  cout << "\nProgram Exited successfully";
  return 0;
}
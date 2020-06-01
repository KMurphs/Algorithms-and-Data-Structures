#include <bits/stdc++.h>

using namespace std;
#define n 3 

struct Path{
  int startVal, endVal;
};

int findLongestPath(int mat[n][n]){
  Path dp[n][n];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      dp[i][j] = { mat[i][j], mat[i][j] };



  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      Path *prev = nullptr;
      
      if(i - 1 >= 0 && mat[i - 1][j] == mat[i][j] - 1) prev = &dp[i - 1][j];
      if(i + 1 < n  && mat[i + 1][j] == mat[i][j] - 1) prev = &dp[i + 1][j];
      if(j - 1 >= 0 && mat[i][j - 1] == mat[i][j] - 1) prev = &dp[i][j - 1];
      if(j + 1 < n  && mat[i][j + 1] == mat[i][j] - 1) prev = &dp[i][j + 1];
      
      if(prev != nullptr){
        int start = min(min(prev->startVal, dp[i][j].startVal), mat[i][j]);
        int end = max(max(prev->endVal, dp[i][j].endVal), mat[i][j]);;
        prev->startVal = start;
        prev->endVal = end;
        dp[i][j] = { start, end };
      }
    }



  int maxPathLength = INT_MIN;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(maxPathLength < (dp[i][j].endVal - dp[i][j].startVal + 1))
        maxPathLength = (dp[i][j].endVal - dp[i][j].startVal + 1);


  return maxPathLength;
}

// https://en.cppreference.com/w/c/language/main_function
// arguments count, 
// arguments vector, 
// environment variables vector
int main(int argc, char **argv, char **envp){

  #define n 3 
  int mat[n][n] = { {1, 2, 9}, {5, 3, 8}, {4, 6, 7} };

  int maxPathLength = findLongestPath(mat);
  cout << "Longest Path is of Length: " << maxPathLength << endl;

  assert(maxPathLength == 4);

  cout << "\nProgram Exited successfully";
  return 0;
}
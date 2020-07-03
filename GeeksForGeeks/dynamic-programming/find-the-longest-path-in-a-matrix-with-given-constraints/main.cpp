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











bool isSafe(int mat[n][n], int row, int col){
  if(row < 0 || row >= n) return false;
  if(col < 0 || col >= n) return false;
  return true;
}

#define INCREMENTS 4
struct TIncrement{
  int drow, dcol;
};
TIncrement increments[INCREMENTS] = {
  {0, -1},
  {0, 1},
  {1, 0},
  {-1, 0},
};



struct Elmt{
  int val, row, col;
};
int findLongestPath2(int mat[n][n]){


  // Sort matrix elemnts, Store along with value position of the elemnt in matrix
  Elmt *elmts = new Elmt[n*n];

  for(int i = 0, k = 0 ; i < n ; i++) 
    for(int j = 0 ; j < n ; j++)
      elmts[k++] = { mat[i][j], i, j };

  sort(elmts, elmts + (n*n), [](const Elmt& elmt1, const Elmt& elmt2) {
    return elmt1.val < elmt2.val;
  });


  // Prepare dp structure, and set to 0's
  int **dp = new int*[n];
  for(int i = 0 ; i < n ; i++){
    dp[i] = new int[n];
    memset(dp[i], 0 , sizeof(int) * n);
  }



  // dp algo
  int maxPath = INT_MIN;
  for(int i = 0 ; i < n*n ; i++){
    for(int j = 0 ; j < INCREMENTS ; j++){

      // Compute next logical point in all four direction
      int nextRow = elmts[i].row + increments[j].drow;
      int nextCol = elmts[i].col + increments[j].dcol;

      // If point is valid and greater than current point
      if(isSafe(mat, nextRow, nextCol) && mat[nextRow][nextCol] > elmts[i].val){
        dp[nextRow][nextCol] = max(dp[elmts[i].row][elmts[i].col] + 1, dp[nextRow][nextCol]);

        // Keep track of maxPath Length
        if(dp[nextRow][nextCol] > maxPath) 
          maxPath = dp[nextRow][nextCol];
      }
    }
  } 


  return maxPath;
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

  assert(maxPathLength == 6);
  assert(findLongestPath2(mat) == 6);

  cout << "\nProgram Exited successfully";
  return 0;
}
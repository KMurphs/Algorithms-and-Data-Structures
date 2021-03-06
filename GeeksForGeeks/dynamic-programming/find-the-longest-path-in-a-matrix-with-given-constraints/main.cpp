#include <bits/stdc++.h>

using namespace std;
#define n 3 

struct Path{
  int startVal, endVal;
};

int dfsUtil(int mat[n][n], int dp[n][n], int i , int j, int lLength){

  int nRow = -1, nCol = -1;
      
  if(i - 1 >= 0 && mat[i - 1][j] == mat[i][j] + 1 && dp[i - 1][j] == 0) nRow = i - 1, nCol = j;
  if(i + 1 < n  && mat[i + 1][j] == mat[i][j] + 1 && dp[i + 1][j] == 0) nRow = i + 1, nCol = j;
  if(j - 1 >= 0 && mat[i][j - 1] == mat[i][j] + 1 && dp[i][j - 1] == 0) nRow = i, nCol = j - 1;
  if(j + 1 < n  && mat[i][j + 1] == mat[i][j] + 1 && dp[i][j + 1] == 0) nRow = i, nCol = j + 1;


  if(nRow == -1){
    dp[i][j] = lLength + 1;
  }else{
    dp[i][j] = dfsUtil(mat, dp, nRow, nCol, lLength + 1);
  }

  
  return dp[i][j];
}




int findLongestPath(int mat[n][n]){
  
  int dp[n][n];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      dp[i][j] = 0;


  int maxPathLength = INT_MIN;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(dp[i][j] == 0){
        dp[i][j] = dfsUtil(mat, dp, i, j, 0);
        if(maxPathLength < dp[i][j])
          maxPathLength = dp[i][j];
      }
    } 
  }
  

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
      if(isSafe(mat, nextRow, nextCol) && (mat[nextRow][nextCol] == (elmts[i].val + 1))){
        dp[nextRow][nextCol] = max(dp[elmts[i].row][elmts[i].col] + 1, dp[nextRow][nextCol]);

        // Keep track of maxPath Length
        if(dp[nextRow][nextCol] > maxPath) 
          maxPath = dp[nextRow][nextCol];
      }
    }
  } 


  return maxPath;
}






// https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
// https://en.cppreference.com/w/c/language/main_function
// arguments count, 
// arguments vector, 
// environment variables vector
int main(int argc, char **argv, char **envp){

  #define n 3 
  int mat[n][n] = { {1, 2, 9}, {5, 3, 8}, {4, 6, 7} };

  int maxPathLength = findLongestPath(mat);
  cout << "Longest Path is of Length: " << maxPathLength << endl;

  assert(maxPathLength == 3);
  assert(findLongestPath2(mat) == 3);

  cout << "\nProgram Exited successfully";
  return 0;
}
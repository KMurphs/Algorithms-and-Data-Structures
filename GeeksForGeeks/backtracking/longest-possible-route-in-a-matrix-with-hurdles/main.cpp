#include <bits/stdc++.h>

using namespace std;

#define R 3 
#define C 10 
#define INCREMENTS 4

struct TPoint{
  int row, col;
  TPoint(int _row, int _col): row(_row), col(_col){}
  TPoint translate(int _row, int _col){
    return *new TPoint(row + _row, col + _col);
  }
  TPoint translate(TPoint *inc){
    return *new TPoint(row + inc->row, col + inc->col);
  }
};

bool isValid(int mat[R][C], TPoint pos){
  if(pos.row < 0 || pos.col < 0) return false;
  if(pos.row >= R || pos.col >= C) return false;
  if(mat[pos.row][pos.col] != 1) return false;
  return true;
}

int findLongestPath(int mat[R][C], TPoint src, TPoint dst){

  TPoint *increments[INCREMENTS] = {
    new TPoint(1, 0),
    new TPoint(0, 1),
    new TPoint(-1, 0),
    new TPoint(0, -1)
  };

  if(src.row == dst.row && src.col == dst.col){
    return 0;
  }

  int maxLength = INT_MIN, tmpLength;

  for(int i = 0 ; i < INCREMENTS ; i++){
    TPoint next = src.translate(increments[i]);
    if(isValid(mat, next)){
      mat[next.row][next.col] = 2;
      tmpLength = findLongestPath(mat, next, dst);
      if(maxLength < tmpLength)
        maxLength = tmpLength;
      mat[next.row][next.col] = 1;
    }
  }
  
  return maxLength + 1;
}



int main(int argc, char **argv, char **envp){


    // input matrix with hurdles shown with number 0 
    int mat[R][C] = 
    { 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } 
    }; 
  
    // find longest path with source (0, 0) and 
    // destination (1, 7) 
    int pathLength = findLongestPath(mat, *new TPoint(0, 0), *new TPoint(1, 7)); 
    assert(pathLength == 24);

  cout << "Program Exited Successfully";
  return 0;
}
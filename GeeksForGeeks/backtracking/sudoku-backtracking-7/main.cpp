#include <bits/stdc++.h>
using namespace std;

#define SIZE 9

enum TCheck{
  ROW,
  COL,
  BLOCK
};


bool isBlockValid(int grid[SIZE][SIZE], int x, int y, TCheck check){

  if(x < 0 || y < 0) return false;
  if(x >= SIZE || y >= SIZE) return false;


  int x0, x1, y0, y1;
  switch (check)
  {
    case ROW:
      x0 = x, x1 = x;
      y0 = 0, y1 = SIZE - 1;
      break;
    case COL:
      y0 = y, y1 = y;
      x0 = 0, x1 = SIZE - 1;
      break;   
    default:
      x0 = (SIZE/3) * (int)(x/(SIZE/3)), x1 = x0 + (SIZE/3) - 1;
      y0 = (SIZE/3) * (int)(y/(SIZE/3)), y1 = y0 + (SIZE/3) - 1;
      break;
  }


  int *sieve = new int[SIZE + 1];
  memset(sieve, 0, (SIZE + 1)*sizeof(int));


  int curr;
  for(int row = x0 ; row <= x1 ; row++){
    for(int col = y0 ; col <= y1 ; col++){

      curr = grid[row][col];
      if(curr >= 0 && curr <= SIZE){
        if(sieve[curr] != 0)
          return false;
        sieve[curr] = curr;
      }

    }
  }


  return true;
}





bool solveSudoku(int grid[SIZE][SIZE], int x = 0, int y = 0){


  int xNext = x, yNext = y;
  do{
    xNext = xNext + 1, yNext = yNext;
    if(xNext >= SIZE){
      xNext = 0, yNext = yNext + 1;
    } 
  }while((xNext < SIZE) && (yNext < SIZE) && grid[xNext][yNext] != 0);

  if(xNext >= SIZE || yNext >= SIZE)
    return true;



  if(grid[xNext][yNext] == 0){
    for(int i = 1 ; i <= SIZE ; i++){
      grid[xNext][yNext] = i;
      if(
        isBlockValid(grid, xNext, yNext, ROW) && 
        isBlockValid(grid, xNext, yNext, COL) && 
        isBlockValid(grid, xNext, yNext, BLOCK) 
      )
        if(solveSudoku(grid, xNext, yNext))
          return true;
    }
    grid[xNext][yNext] = 0;
  }

  
  return false;
}


// https://www.geeksforgeeks.org/sudoku-backtracking-7/
int main(int argc, char **argv, char **envp){


  int grid[SIZE][SIZE] = { 
          // {1, 2, 3, 4, 4, 6, 7, 8, 9}, 
          {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
          {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
          {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
          {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
          {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
          {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
          {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
          {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
          {0, 0, 5, 2, 0, 6, 3, 0, 0} 
  };

  // assert(!isBlockValid(grid, 0, 0, ROW));
  assert(isBlockValid(grid, 4, 7, ROW));
  assert(isBlockValid(grid, 4, 7, COL));
  assert(isBlockValid(grid, 4, 7, BLOCK));

  bool isSolved = solveSudoku(grid);
  assert(isSolved);

  int grid2[SIZE][SIZE] = { 
        { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
        { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
        { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
        { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
        { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
        { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
        { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
        { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
        { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };

  isSolved = solveSudoku(grid2);
  assert(isSolved);

  cout << "Program is exiting..." << endl; 
  return 0; 
}
#include <bits/stdc++.h>

using namespace std;


struct TPoint{
  int row, col;
  TPoint(int r, int c): row(r), col(c){}
  TPoint *translate(TPoint *inc){
    return new TPoint(row + inc->row, col + inc->col); 
  }
};

#define INCREMENTS 2
TPoint *increments[INCREMENTS] = {
  new TPoint(0, 1),
  new TPoint(1, 0)
};




bool isValid(int **arr, int rows, int cols, TPoint *pos){

  if(pos->row < 0 || pos->row >= rows) return false;
  if(pos->col < 0 || pos->col >= cols) return false;

  return true;
}





void explore(int **arr, int rows, int cols, int *nPaths, TPoint *src, TPoint *dst, vector<int> currPath){

  if(src->row == dst->row && src->col == dst->col){
    (*nPaths)++;
    for(vector<int>::iterator it = currPath.begin() ; it != currPath.end() ; ++it)
      cout << *it << "  ";
    cout << endl;
    return;
  }


  for(int i = 0 ; i < INCREMENTS ; i++){
    TPoint *next = src->translate(increments[i]);
    if(isValid(arr, rows, cols, next)){
      currPath.push_back(arr[next->row][next->col]);
      explore(arr, rows, cols, nPaths, next, dst, currPath);
      currPath.pop_back();
    }
  }

}




int findPaths(int **arr, int rows, int cols){

  int nPaths = 0;
  vector<int> currPath = *new vector<int>();
  currPath.push_back(arr[0][0]);
  explore(arr, rows, cols, &nPaths, new TPoint(0, 0), new TPoint(rows - 1, cols - 1), currPath);

  return nPaths;
}




// https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/
int main(int argc, char **argv, char **envp){

  int **arr, rows, cols, exp;




  rows = 2, cols = 3, arr = new int*[rows], exp = 3;
  arr[0] = new int[cols]{1, 2, 3};
  arr[1] = new int[cols]{4, 5, 6};
  assert(findPaths(arr, rows, cols) == exp);


  rows = 2, cols = 2, arr = new int*[rows], exp = 2;
  arr[0] = new int[cols]{1, 2};
  arr[1] = new int[cols]{3, 4};
  assert(findPaths(arr, rows, cols) == exp);
  



  cout << "Program Exited Successfully";
  return 0;
}
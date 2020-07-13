#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct TBox{
  int h, w, d;
  TBox(int _h = 0, int _d = 0, int _w = 0): h(_h), d(_d), w(_w){}
};




TBox getArrangement(TBox elmt, int r){
  if(r == 2) return (elmt.d > elmt.h ? *new TBox(elmt.w, elmt.d, elmt.h) : *new TBox(elmt.w, elmt.h, elmt.d));
  if(r == 1) return (elmt.w > elmt.h ? *new TBox(elmt.d, elmt.w, elmt.h) : *new TBox(elmt.d, elmt.h, elmt.w));
  return (elmt.w > elmt.d ? *new TBox(elmt.h, elmt.w, elmt.d) : *new TBox(elmt.h, elmt.d, elmt.w));
}


int stackBoxesForMaxHeightUtil2(TBox *arr, int n, bool *visited, int currD, int currW, TBox *sol, int solIdx){


  int maxHeight = 0, tmpHeight;
  for (int i = 0; i < n; i++){
    if(!visited[i]){
      
      visited[i] = 1;
      for(int r = 0 ; r < 3 ; r++){

        TBox tmp = getArrangement(arr[i], r);
        if(currD >= tmp.d && currW >= tmp.w && (currD*currW < tmp.d*tmp.w)){
          tmpHeight = stackBoxesForMaxHeightUtil2(arr, n, visited, tmp.d, tmp.w, sol, solIdx + 1) + tmp.h;
          
          if(tmpHeight > maxHeight){
            maxHeight = tmpHeight;
            sol[solIdx] = tmp;
          }
        }

      }
      visited[i] = 0;

    }
  }
  return maxHeight;
}
int stackBoxesForMaxHeight2(TBox *arr, int n){
  bool *visited = new bool[n];
  memset(visited, 0, sizeof(bool) * n);
  TBox *sol = new TBox[n];
  memset(visited, 0, sizeof(TBox) * n);
  int h = stackBoxesForMaxHeightUtil2(arr, n, visited, INT_MAX, INT_MAX, sol, 0);
  for(int i = 0 ; i < n ; i++)
    cout << "(" << sol[i].h << ", " << sol[i].d << ", " << sol[i].w << ")"; 
  return h;
}





int stackBoxesForMaxHeightUtil(TBox *arr, int n, bool *visited, int currD, int currW){

  int maxHeight = 0, tmpHeight = 0;
  for (int i = 0; i < n; i++){
    if(!visited[i]){
      
      visited[i] = 1;
      if(currD > arr[i].d && currW > arr[i].w){
        
        tmpHeight = stackBoxesForMaxHeightUtil(arr, n, visited, arr[i].d, arr[i].w) + arr[i].h;
        if(tmpHeight > maxHeight){
          maxHeight = tmpHeight;      
        }
      }
      visited[i] = 0;

    }
  }



  return maxHeight;
}


int stackBoxesForMaxHeight(TBox *arr, int n){
  
  TBox *newArr = new TBox[3*n];
  int maxNum = 0;
  for(int i = 0 ; i < n ; i++){
    for(int r = 0 ; r < 3 ; r++){
      newArr[3*i + r] = getArrangement(arr[i], r);
      if(maxNum < newArr[3*i + r].h){
        maxNum = newArr[3*i + r].h;
      }
    }
  }


  bool *visited = new bool[3*n];
  memset(visited, 0, sizeof(bool) * 3*n);
  int h = stackBoxesForMaxHeightUtil(newArr, 3*n, visited, maxNum + 1, maxNum + 1);
  return h;
}





// https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
int main(){

    int n, exp;
    TBox *arr;

    n = 4, arr = new TBox[n]{{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}}, exp = 60;
    assert(stackBoxesForMaxHeight(arr, n) == exp);



    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
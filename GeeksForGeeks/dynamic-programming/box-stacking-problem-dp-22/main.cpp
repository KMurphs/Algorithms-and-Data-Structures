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



int stackBoxesForMaxHeightUtil2(TBox *arr, int n){

  int i = n;
  while(arr[i].d >= arr[n].d || arr[i].w >= arr[n].w) {
    i--;
    if(i < 0){
      return arr[n].h;
    }
  }
    
  return stackBoxesForMaxHeightUtil2(arr, i) + arr[n].h;
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

  sort(newArr, newArr + (3*n), [](const TBox b1, const TBox b2) {
    return (b1.d < b2.d) || ((b1.d == b2.d) && (b1.w < b2.w));
  });

  for(int i = 0 ; i < 3*n ; i++)
    cout << "(" << newArr[i].h << ", " << newArr[i].d << ", " << newArr[i].w << ")" << "   ";
  cout << endl;

  int h = stackBoxesForMaxHeightUtil2(newArr, 3*n - 1);
  cout << h << endl;
  return h;



  bool *visited = new bool[3*n];
  memset(visited, 0, sizeof(bool) * 3*n);

  return stackBoxesForMaxHeightUtil(newArr, 3*n, visited, maxNum + 1, maxNum + 1);
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
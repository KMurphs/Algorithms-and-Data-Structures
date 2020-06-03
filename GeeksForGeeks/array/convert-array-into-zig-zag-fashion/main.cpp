#include <bits/stdc++.h>

using namespace std;

void Swap(int arr[], int l, int r){
  int tmp = arr[l];
  arr[l] = arr[r];
  arr[r] = tmp;
}

void zigzagArray(int *arr, int arrSize){

  // Arrange groups of 3's by ensuring max/min of group is always in middle
  // Arrangement is alternated between groups 
  // i.e groups 1 (up down up), group 2 (down up down), group 3 (up down up),...
  bool searchingForMax = true;
  for(int i = 0; i < arrSize; i = i + 3){
    int extremaVal = arr[i], extremaIdx = i;
    for(int j = i; j < i + 3 && j < arrSize; j++){
      if(
        ( searchingForMax && extremaVal < arr[j]) ||
        (!searchingForMax && extremaVal > arr[j])
      ){
        extremaVal = arr[j];
        extremaIdx = j;
      }
    }
    if(i + 1 < arrSize) Swap(arr, extremaIdx, i + 1);
    searchingForMax = !searchingForMax;
  }


  // Walk array, and fix groups borders
  bool directionIs_LessThan = true;
  for(int i = 1; i < arrSize; i++){

    bool isInOrder;
    if(directionIs_LessThan) isInOrder = arr[i - 1] < arr[i];
    else isInOrder = arr[i - 1] > arr[i];

    if(!isInOrder) Swap(arr, i - 1 ,i);

    directionIs_LessThan = !directionIs_LessThan;
  }

}


// https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
// Inspired by bubble sort
// Program for zig-zag conversion of array 
void zigzagArrayBubbleSort(int arr[], int n) 
{ 
    // Flag true indicates relation "<" is expected, 
    // else ">" is expected.  The first expected relation 
    // is "<" 
    bool flag = true; 
  
    for (int i=0; i<=n-2; i++) 
    { 
        if (flag)  /* "<" relation expected */
        { 
            /* If we have a situation like A > B > C, 
               we get A > B < C by swapping B and C */
            if (arr[i] > arr[i + 1]) 
                Swap(arr, i, i + 1); 
        } 
        else /* ">" relation expected */
        { 
            /* If we have a situation like A < B < C, 
               we get A < C > B by swapping B and C */
            if (arr[i] < arr[i + 1]) 
                Swap(arr, i, i + 1); 
        } 
        flag = !flag; /* flip flag */
    } 
} 











// https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
// a < b > c < d > e < f
int main(int argc, char **argv, char **envp){

  
  int arrSize, *arr;
  bool checkWith_LessThan; 
  


  arrSize = 7, arr = new int[arrSize]{4, 3, 7, 8, 6, 2, 1}, checkWith_LessThan = true;
  zigzagArray(arr, arrSize);
  for(int i = 1; i < arrSize; i++){
    if(checkWith_LessThan) assert(arr[i - 1] < arr[i]);
    else assert(arr[i - 1] > arr[i]);
    checkWith_LessThan = !checkWith_LessThan;
  }

  arrSize = 7, arr = new int[arrSize]{4, 3, 7, 8, 6, 2, 1}, checkWith_LessThan = true;
  zigzagArrayBubbleSort(arr, arrSize);
  for(int i = 1; i < arrSize; i++){
    if(checkWith_LessThan) assert(arr[i - 1] < arr[i]);
    else assert(arr[i - 1] > arr[i]);
    checkWith_LessThan = !checkWith_LessThan;
  }


  arrSize = 4, arr = new int[arrSize]{1, 4, 3, 2}, checkWith_LessThan = true;
  zigzagArray(arr, arrSize);
  for(int i = 1; i < arrSize; i++){
    if(checkWith_LessThan) assert(arr[i - 1] < arr[i]);
    else assert(arr[i - 1] > arr[i]);
    checkWith_LessThan = !checkWith_LessThan;
  }
  
  arrSize = 4, arr = new int[arrSize]{1, 4, 3, 2}, checkWith_LessThan = true;
  zigzagArrayBubbleSort(arr, arrSize);
  for(int i = 1; i < arrSize; i++){
    if(checkWith_LessThan) assert(arr[i - 1] < arr[i]);
    else assert(arr[i - 1] > arr[i]);
    checkWith_LessThan = !checkWith_LessThan;
  }



  cout << "Program Exited Successfully";
  return 0;
}
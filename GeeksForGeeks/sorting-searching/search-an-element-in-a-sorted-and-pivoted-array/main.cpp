#include <bits/stdc++.h>


using namespace std;

int rotatedBinarySearch(int arr[], int l, int r, int elementVal){

  if(l <= r){
  
    int m = l + (r - l)/2;
    if(arr[m] == elementVal) return m;

    // Track normal binary search
    if(arr[m] < elementVal){

      // 3 cases are possible: 2 cases fall in the same region
      // check for the other case, and let both identical case fall back to the default else
      // to build this condition 3 out 4 values are needed (l, m, elementVal)
      if(arr[l] > arr[m] && elementVal >= arr[l]) return rotatedBinarySearch(arr, l, m - 1, elementVal);
      else return rotatedBinarySearch(arr, m + 1, r, elementVal);

    }else{

      if(arr[r] < arr[m] && elementVal <= arr[r]) return rotatedBinarySearch(arr, m + 1, r, elementVal);
      else return rotatedBinarySearch(arr, l, m - 1, elementVal);

    }
  
  }

  return -1;
}



int main(){
  #define SIZE 5

  int arr[SIZE] = { 10, 40, 2, 3, 4 };
  int elmtVal = 3;
  int elmtIdx = rotatedBinarySearch(arr, 0, SIZE - 1, elmtVal);

  cout << "Element '" << elmtVal << "' is at index: '" << elmtIdx << "'" << endl;

  assert(rotatedBinarySearch(arr, 0, SIZE - 1, 2) == 2);
  assert(rotatedBinarySearch(arr, 0, SIZE - 1, 3) == 3);
  assert(rotatedBinarySearch(arr, 0, SIZE - 1, 4) == 4);
  assert(rotatedBinarySearch(arr, 0, SIZE - 1, 10) == 0);
  assert(rotatedBinarySearch(arr, 0, SIZE - 1, 40) == 1);
  assert(rotatedBinarySearch(arr, 0, SIZE - 1, 5) == -1);
  assert(rotatedBinarySearch(arr, 0, SIZE - 1, 0) == -1);
  assert(rotatedBinarySearch(arr, 0, SIZE - 1, 50) == -1);

  cout << "\n\n\nProgram exited successfully..." << endl;
  return 0;
}
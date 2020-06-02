#include <bits/stdc++.h>


using namespace std;

int binarySearch(int arr[], int arrSize, int elementVal){

  int l = 0, r = arrSize - 1, m;

  while(r - l > 1){
    m = l + (r - l)/2;
    if(arr[m] <= elementVal) l = m;
    else r = m;
  }

  if(arr[l] == elementVal) return l;
  if(arr[r] == elementVal) return r;
  return -1;

}



int main(){
  #define SIZE 5

  int arr[SIZE] = { 2, 3, 4, 10, 40 };
  int elmtVal = 3;
  int elmtIdx = binarySearch(arr, SIZE, elmtVal);

  cout << "Element '" << elmtVal << "' is at index: '" << elmtIdx << "'" << endl;

  assert(binarySearch(arr, SIZE, 2) == 0);
  assert(binarySearch(arr, SIZE, 3) == 1);
  assert(binarySearch(arr, SIZE, 4) == 2);
  assert(binarySearch(arr, SIZE, 10) == 3);
  assert(binarySearch(arr, SIZE, 40) == 4);
  assert(binarySearch(arr, SIZE, 5) == -1);
  assert(binarySearch(arr, SIZE, 0) == -1);
  assert(binarySearch(arr, SIZE, 50) == -1);

  cout << "\n\n\nProgram exited successfully..." << endl;
  return 0;
}
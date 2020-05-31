#include <bits/stdc++.h>

using namespace std;

void Swap(int arr[], int l, int r){
  int tmp = arr[l];
  arr[l] = arr[r];
  arr[r] = tmp;
}


int partition(int arr[], int l, int r){
  int pivotIdx = r, pivotVal = arr[r];
  int cache = l - 1;
  for(int i = l; i < r; i++){
    if(arr[i] < pivotVal){
      Swap(arr, i, ++cache);
    }
  }
  Swap(arr, ++cache, pivotIdx);
  return cache;
}


void quicksort(int arr[], int l, int r){
  if(l < r){
    int pivot = partition(arr, l, r);
    quicksort(arr, l, pivot - 1);
    quicksort(arr, pivot + 1, r);
  }
}



int main(){
  
  #define SIZE 9

  int arr[SIZE] = {2, 3, 5, 6, 8, 7, 4, 1, 9};
  quicksort(arr, 0, SIZE - 1);

  for(int i = 0 ; i < SIZE ; i++)
    cout << arr[i] << " ";
  cout << endl;

  assert(arr[0] == 1);
  assert(arr[SIZE - 1] == 9);

  cout << "Program exited successully..." << endl;
  return 0;
}
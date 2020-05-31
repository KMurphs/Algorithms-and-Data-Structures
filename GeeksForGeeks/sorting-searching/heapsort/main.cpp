#include <bits/stdc++.h>


using namespace std;

void Swap(int arr[], int l, int r){
  int tmp = arr[l];
  arr[l] = arr[r];
  arr[r] = tmp;
}

void heapify(int arr[], int heapSize, int parentIdx){
  int ch1Idx = 2 * parentIdx + 1;
  int ch2Idx = 2 * parentIdx + 2;
  int maxFamily = parentIdx;

  if(ch1Idx < heapSize && arr[maxFamily] < arr[ch1Idx])
    maxFamily = ch1Idx;
  if(ch2Idx < heapSize && arr[maxFamily] < arr[ch2Idx])
    maxFamily = ch2Idx;
  if(maxFamily != parentIdx){
    Swap(arr, parentIdx, maxFamily);
    heapify(arr, heapSize, maxFamily);
  }
}

void heapsort(int arr[], int size){

  for(int i = 1 + (size/2); i >= 0; i--){
    heapify(arr, size, i);
  }
  for(int i = size - 1; i >= 0; i--){
    Swap(arr, 0, i);
    heapify(arr, i, 0);
  }  

}



int main(){
  #define SIZE 9

  int arr[SIZE] = {2, 3, 5, 6, 8, 7, 4, 1, 9};
  heapsort(arr, SIZE);

  for(int i = 0 ; i < SIZE ; i++)
    cout << arr[i] << " ";
  cout << endl;

  assert(arr[0] == 1);
  assert(arr[SIZE - 1] == 9);

  cout << "\n\n\nProgram exited successfully..." << endl;
  return 0;
}
#include <bits/stdc++.h>


using namespace std;

void Swap(int arr[], int l, int r){
  int tmp = arr[l];
  arr[l] = arr[r];
  arr[r] = tmp;
}



void selectionsort(int arr[], int arrSize){

  for(int i = 0 ; i < arrSize - 1 ; i++){
    int minIdx = i;
    for(int j = i + 1 ; j < arrSize ; j++){
      if(arr[minIdx] > arr[j]){
        minIdx = j;
      }
    }
    Swap(arr, minIdx, i);
  }

}



int main(){
  #define SIZE 9

  int arrSize, *arr;

  arrSize = 9, arr = new int[arrSize]{2, 3, 5, 6, 8, 7, 4, 1, 9};
  selectionsort(arr, arrSize);
  for(int i = 1 ; i < arrSize ; i++)
    assert(arr[i - 1] <= arr[i]);


  for(int i = 0 ; i < SIZE ; i++)
    cout << arr[i] << " ";
  cout << endl;


  arrSize = 9, arr = new int[arrSize]{2, 3, 5, 6, 9, 7, 4, 1, 8};
  selectionsort(arr, arrSize);
  for(int i = 1 ; i < arrSize ; i++)
    assert(arr[i - 1] <= arr[i]);


  arrSize = 9, arr = new int[arrSize]{9, 8, 7, 6, 5, 4, 3, 2, 1};
  selectionsort(arr, arrSize);
  for(int i = 1 ; i < arrSize ; i++)
    assert(arr[i - 1] <= arr[i]);

  arrSize = 9, arr = new int[arrSize]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  selectionsort(arr, arrSize);
  for(int i = 1 ; i < arrSize ; i++)
    assert(arr[i - 1] <= arr[i]);

  cout << "\n\n\nProgram exited successfully..." << endl;
  return 0;
}
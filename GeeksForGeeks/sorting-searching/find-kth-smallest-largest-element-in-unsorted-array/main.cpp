#include <bits/stdc++.h>

using namespace std;

void Swap(int arr[], int l, int r){
  int tmp = arr[l];
  arr[l] = arr[r];
  arr[r] = tmp;
}

int partition(int arr[], int l, int r){
  // int pivot = l + rand()%(r - l); 
  // Swap(arr, pivot, r);

  int pivot = r;
  int pivotVal = arr[r];

  int cache = -1;

  for(int i = l; i < r; i++){
    if(arr[i] < pivotVal){
      cache++;
      Swap(arr, cache, i);
    }
  }

  Swap(arr, cache + 1, pivot);
  return cache + 1;
}




int findKthLargest(int arr[], int l, int r, int K){
  int pivot = partition(arr, l, r);

  if(pivot == K - 1) return arr[pivot]; 

  if(pivot > K - 1){
    return findKthLargest(arr, l, pivot - 1, K);
  }

  return findKthLargest(arr, pivot + 1, r, K - pivot);
}


int main(){
  int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
  int K = 5;

  int kth = findKthLargest(arr, 0, 6, K);
  cout << K << "th Largest Element is: " << kth << endl;

  assert(findKthLargest(arr, 0, 6, 5) == 5);
  assert(findKthLargest(arr, 0, 6, 1) == 1);


  cout << "Program exited successfully..." << endl;
  return 0;

}
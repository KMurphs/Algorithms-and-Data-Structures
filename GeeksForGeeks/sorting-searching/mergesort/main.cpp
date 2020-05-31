#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r){
  int il, ir, ik;
  int nl = m - l + 1, nr = r - m;
  
  int *arrl = new int[nl];
  int *arrr = new int[nr];


  for(il = 0; il < nl; il++)
    arrl[il] = arr[l + il];
  for(ir = 0; ir < nr; ir++)
    arrr[ir] = arr[m + ir + 1];



  il = 0, ir = 0, ik = l;
  while(il < nl && ir < nr){
    if(arrl[il] > arrr[ir]){
      arr[ik++] = arrr[ir++];
    }else{
      arr[ik++] = arrl[il++];
    }
  }

  while(il < nl){
    arr[ik++] = arrl[il++];
  }
  while(ir < nr){
    arr[ik++] = arrr[ir++];
  }
}


void mergesort(int arr[], int l, int r){
  if(l < r){
    int m = l + (r - l)/2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}


int main(){
  #define SIZE 9

  int arr[SIZE] = {2, 3, 5, 6, 8, 7, 4, 1, 9};
  mergesort(arr, 0, SIZE - 1);

  for(int i = 0 ; i < SIZE ; i++)
    cout << arr[i] << " ";
  cout << endl;

  assert(arr[0] == 1);
  assert(arr[SIZE - 1] == 9);

  cout << "\n\nProgram Exited successfully..." << endl;
  return 0;
}
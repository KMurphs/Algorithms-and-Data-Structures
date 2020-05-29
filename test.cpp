// #include <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main(int argc, char **argv){
  int *arr = new int[4];
  memset(arr, -1, 4 * sizeof(int));
  for(int i = 0 ; i < 4 ; i++) 
    cout << arr[i] << "  ";
  return 0;
}
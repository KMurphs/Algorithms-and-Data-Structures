#include <bits/stdc++.h>
using namespace std;


bool findMissing(int *arr, int *map, int arrSize, int k, int target, int currSum){

  if(currSum > target) return false;
  if(currSum == target) return true;


  for(int i = 0 ; i < arrSize ; i++){
    if(map[i] == 0){
      map[i] = k;
      if(findMissing(arr, map, arrSize, k, target, currSum + arr[i])){
        return true;
      }
      map[i] = 0;
    }
  }


  return false;
}


int *partition(int *arr, int arrSize, int K){

  int *map = new int[arrSize], *inv = new int[arrSize];
  memset(map, 0 , sizeof(int) * arrSize);
  memset(inv, 0 , sizeof(int) * arrSize);

  int sum = accumulate(arr, arr + arrSize, 0), target = 0;
  sort(arr, arr + arrSize);
  target = sum / 3;


  if(sum % 3 != 0) return inv;
  if(arr[arrSize - 1] > target && arr[0] > 0) return inv;


  for(int k = 1, i = arrSize - k ; k <= K ; k++){
    
    while(i >= 0 && map[i] != 0) i--;
    if(i < 0) return inv;

    map[i] = k;
    if(!findMissing(arr, map, arrSize, k, target, arr[i])) 
      return inv;

  }

  return map;
}

// https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
int main(){

    int arrSize, *arr, K, *map, sumT; 
    bool isPartitioned;

    arrSize = 5, arr = new int[arrSize]{2, 1, 4, 5, 6}, K = 3, sumT = 0;
    map = partition(arr, arrSize, K);
    for(int i = 0 ; i < arrSize ; i++){
      sumT = sumT + arr[i];
      assert(map[i] != 0);
    }
    for(int k = 1 ; k <= K ; k++){
      int sum = 0;
      cout << "(" << sumT/3 << "): ";
      for(int i = 0 ; i < arrSize ; i++){
        if(map[i] == k){
          cout << arr[i] << "  ";
          sum = sum + arr[i];
        }
      }
      cout << endl;
      assert(sum == sumT/3);
    }


    arrSize = 5, arr = new int[arrSize]{2, 1, 5, 5, 6}, K = 3, sumT = 0;
    map = partition(arr, arrSize, K);
    for(int i = 0 ; i < arrSize ; i++){
      sumT = sumT + arr[i];
      assert(map[i] == 0);
    }


    cout << "Program is exiting..." << endl; 
    return 0; 
}
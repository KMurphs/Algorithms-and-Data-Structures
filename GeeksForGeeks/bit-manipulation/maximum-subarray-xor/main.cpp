#include <bits/stdc++.h>

using namespace std;

int findMaximumXOR(int arr[], int arrSize, int **resSol, int *resSolSize){

  int max_i, max_j, max_val = INT_MIN, curr_val;
  for(int i = 0; i < arrSize; i++){
    curr_val = 0;

    for(int j = i; j < arrSize; j++){
      curr_val = curr_val ^ arr[j];
      if(curr_val > max_val) { max_i = i, max_j = j, max_val = curr_val; }
    }
    
  }


  *resSolSize = max_j - max_i + 1;
  *resSol = new int[*resSolSize];
  for(int i = 0; i < *resSolSize; i++){
    (*resSol)[i] = arr[max_i + i];
  }

  return max_val;
}

int main(int argc, char **argv, char **envp){

  int size, *arr, expVal, expSolSize, *expSol, resVal, resSolSize, *resSol; 
  
  size = 4, arr = new int[size]{1, 2, 3, 4}, expVal = 7, expSolSize = 2, expSol = new int[expSolSize]{3, 4}; 
  resVal = findMaximumXOR(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);


  size = 6, arr = new int[size]{8, 1, 2, 12, 7, 6}, expVal = 15, expSolSize = 3, expSol = new int[expSolSize]{1, 2, 12}; 
  resVal = findMaximumXOR(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);


  size = 2, arr = new int[size]{4, 6}, expVal = 6, expSolSize = 1, expSol = new int[expSolSize]{6}; 
  resVal = findMaximumXOR(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);


  cout << "\nProgram Exited Successfully";
  return 0;
}
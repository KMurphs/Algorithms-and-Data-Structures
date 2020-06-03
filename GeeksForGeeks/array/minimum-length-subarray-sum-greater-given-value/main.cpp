#include <bits/stdc++.h>

using namespace std;



int *minSubarrayWithSumOverTargetUtil(int *arr, int arraySize, int target){
  
  int globalMin = INT_MAX, globalMinStart = 0, globalMinEnd = -2;
  int l = 0, r = 0, rollingSum = arr[0];
  while(r < arraySize){

    if(rollingSum <= target) rollingSum = rollingSum + arr[++r];
    else {
      if(rollingSum < globalMin){
        globalMin = rollingSum;
        globalMinStart = l;
        globalMinEnd = r;
      }
      rollingSum = rollingSum - arr[l++];
    }

  } 


  int *coords = new int[3]{ globalMinStart, globalMinEnd, globalMin };
  return coords;
}




int minSubarrayWithSumOverTarget(int *arr, int arraySize, int target){
  
  int *sol = minSubarrayWithSumOverTargetUtil(arr, arraySize, target);


  for(int i = sol[0] ; i <= sol[1] ; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Sum: " << sol[2] << endl;


  return sol[1] - sol[0] + 1;
}






// https://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/
int main(int argc, char **argv, char **envp){

  
  int arrSize, *arr, target, exp; 
  


  arrSize = 6, arr = new int[arrSize]{1, 4, 45, 6, 0, 19}, target = 51, exp = 3;
  assert(minSubarrayWithSumOverTarget(arr, arrSize, target) == exp);

  arrSize = 5, arr = new int[arrSize]{1, 10, 5, 2, 7}, target = 9, exp = 1;
  assert(minSubarrayWithSumOverTarget(arr, arrSize, target) == exp);

  arrSize = 10, arr = new int[arrSize]{1, 11, 100, 1, 0, 200, 3, 2, 1, 250}, target = 280, exp = 4;
  assert(minSubarrayWithSumOverTarget(arr, arrSize, target) == exp);

  arrSize = 3, arr = new int[arrSize]{1, 2, 4}, target = 8, exp = -1;
  assert(minSubarrayWithSumOverTarget(arr, arrSize, target) == exp);

  cout << "Program Exited Successfully";
  return 0;
}
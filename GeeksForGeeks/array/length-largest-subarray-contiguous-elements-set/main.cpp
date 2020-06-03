#include <bits/stdc++.h>

using namespace std;



// Not working
// ... 4, 5, 6, 9, 10, 3 ...
int longestSubArrayOfContiguous1(int *arr, int arrSize){

  // Get min and max value of array
  int minVal = arr[0], maxVal = arr[0];
  for(int i = 1; i < arrSize; i++){
    if(minVal > arr[i]) minVal = arr[i];
    if(maxVal < arr[i]) maxVal = arr[i];
  }
 
  // We are essentially trasnforming the problem space
  // instead of using the array, we use an array spanning
  // min values to max values

  // Create auxialliary array with length max-min
  // Fill auxialliary with 0
  // Fill auxialliary with value in the original array
  int auxSize = maxVal - minVal + 1, *auxSpace = new int[auxSize];
  memset(auxSpace, 0, auxSize * sizeof(int));
  for(int i = 0; i < arrSize; i++){
    auxSpace[arr[i] - minVal] = arr[i];
  }

  // walk through aux space, and latch the longest block of non 0 values
  int localLength = 0, maxLength = INT_MIN;
  for(int i = 0; i < auxSize; i++){

    if(auxSpace[i] == 0) {
      if(maxLength < localLength) maxLength = localLength;
      localLength = 0;

    } else {
      localLength++;

    }
  }
  if(maxLength < localLength) maxLength = localLength; // edge case: last element in aux is not 0



  return maxLength;
}




int longestSubArrayOfContiguous2(int *arr, int arrSize){

  bool foundSubarray = false;
  int localLength = 0, maxLength = INT_MIN;
  int minIdx = 0, maxIdx = 0, r = 0, l = 0;
  for(l = 0; l < arrSize; l++){
    minIdx = l; 
    maxIdx = l;
    set<int> dups;
    dups.insert(arr[l]);



    for(r = l + 1; r < arrSize; r++){

      // If we find a dup, we don't have a contiguous set of element meeting the invariant
      if(dups.find(arr[r]) != dups.end()) break;
      dups.insert(arr[r]);

      if(arr[minIdx] > arr[r]) minIdx = r;
      if(arr[maxIdx] < arr[r]) maxIdx = r;
      localLength = r - l + 1;



      // invariant: if a subarray respond to the criteria, we have
      // arr[maxIdx] - arr[minIdx] == r - l
      // where maxIdx: index of max value in sub array
      // where minIdx: index of min value in sub array
      // where r: index of end of sub array
      // where l: index of start of sub array
      if(maxIdx < arrSize && minIdx < arrSize && arr[maxIdx] - arr[minIdx] == r - l){
        if(maxLength < localLength) maxLength = localLength;
        foundSubarray = true;
        // It is not straight forward to be clever about this and say that: if the invariant is met
        // we can conclude that a new group will start after the index r
        // Edge case: the sub array is sorted with valid seq ( ... 90, 91, 92, 93 ... )
        // and we need to update r, min and max and recalculate the invariant
      }else{

        // We are coming out of a subarray meeting the invariant
        // and the current one does not match it
        // if(foundSubarray){
        //   foundSubarray = false;
        //   l = r;
        //   minIdx = r;
        //   maxIdx = r;
        //   r = r + 1;
        // }
        // We can't do this because of ... 1, 2, 3, 5, 4, ...

      }


    }
  }

  return maxLength;
}



// https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/
int main(int argc, char **argv, char **envp){

  int arrSize, *arr, exp;
  

  arrSize = 3, arr = new int[arrSize]{10, 12, 11}, exp = 3;
  // assert(longestSubArrayOfContiguous1(arr, arrSize) == exp);
  assert(longestSubArrayOfContiguous2(arr, arrSize) == exp);

  arrSize = 4, arr = new int[arrSize]{14, 12, 11, 20}, exp = 2;
  // assert(longestSubArrayOfContiguous1(arr, arrSize) == exp);
  assert(longestSubArrayOfContiguous2(arr, arrSize) == exp);

  arrSize = 10, arr = new int[arrSize]{1, 56, 58, 57, 90, 92, 94, 93, 91, 45}, exp = 5;
  // assert(longestSubArrayOfContiguous1(arr, arrSize) == exp);
  assert(longestSubArrayOfContiguous2(arr, arrSize) == exp);

  arrSize = 12, arr = new int[arrSize]{1, 56, 58, 57, 90, 92, 92, 94, 90, 93, 91, 45}, exp = 5;
  // assert(longestSubArrayOfContiguous1(arr, arrSize) == exp);
  assert(longestSubArrayOfContiguous2(arr, arrSize) == exp);

  arrSize = 7, arr = new int[arrSize]{10, 12, 12, 10, 10, 11, 10}, exp = 2;
  // assert(longestSubArrayOfContiguous1(arr, arrSize) == exp);
  assert(longestSubArrayOfContiguous2(arr, arrSize) == exp);



  std::cout << "Program Exited Successfully";
  return 0;
}
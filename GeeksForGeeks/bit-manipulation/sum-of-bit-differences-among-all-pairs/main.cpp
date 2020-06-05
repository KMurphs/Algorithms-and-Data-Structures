#include <bits/stdc++.h>

using namespace std;


// Given an integer array of n integers, find sum of bit differences in all pairs that can be formed from array elements. 
// Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y.
// For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers). 
int sumOfBitsDifferences(int *arr, int arrSize){

  int sum = 0;
  
  for(int i = 0, mask = 1; i < 8*sizeof(arr[0]); i++, mask = mask << 1){
    int nSetBits = 0;
    for(int j = 0; j < arrSize; j++){
      nSetBits += arr[j] & mask;
    }
    nSetBits >>= i;
    sum += 2 * nSetBits * (arrSize - nSetBits);
  }

  return sum;
}



// https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
int main(int argc, char **argv, char **envp){

  int arrSize, *arr, exp; 
  
  arrSize = 2, arr = new int[arrSize]{ 1, 2 }, exp = 4;
  assert(sumOfBitsDifferences(arr, arrSize) == exp);


  arrSize = 3, arr = new int[arrSize]{1, 3, 5}, exp = 8;
  assert(sumOfBitsDifferences(arr, arrSize) == exp);



  cout << "\nProgram Exited Successfully";
  return 0;
}
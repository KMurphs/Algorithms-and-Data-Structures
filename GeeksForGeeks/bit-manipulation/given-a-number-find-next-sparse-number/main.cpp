#include <bits/stdc++.h>

using namespace std;


// Given an array where every element occurs three times, except one element which occurs only once. 
// Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
int getUniqueElement(int *arr, int arrSize){

  int elmt = 0;

  for(int bit = 1, shifts = 0; bit != 0; bit = bit << 1, shifts++){
    int sum = 0;
    for(int i = 0 ; i < arrSize ; i++){
      sum += (arr[i] & bit);
    }
    sum = sum >> shifts;
    sum = sum % 3;
    elmt = elmt | ((sum & 1) << shifts);
  }

  return elmt;
}

// int getUniqueElement1(int *arr, int arrSize){

//   int ones = 0, twos = 0, threes = 0;

//   for(int i = 0 ; i < arrSize ; i++){

//   }

//   return 0;
// }


// https://www.geeksforgeeks.org/find-the-element-that-appears-once/
int main(int argc, char **argv, char **envp){

  int arrSize, *arr, exp;


  arrSize = 10; arr = new int[arrSize]{12, 1, 12, 3, 12, 1, 1, 2, 3, 3}; exp = 2; 
  assert(getUniqueElement(arr, arrSize) == exp);


  arrSize = 7; arr = new int[arrSize]{10, 20, 10, 30, 10, 30, 30}; exp = 20; 
  assert(getUniqueElement(arr, arrSize) == exp);




  cout << "\nProgram Exited Successfully";
  return 0;
}
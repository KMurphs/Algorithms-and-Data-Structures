#include <bits/stdc++.h>

using namespace std;


// Given an array where every element occurs three times, except one element which occurs only once. 
// Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
int getUniqueElement1(int *arr, int arrSize){

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


// The key to understand this is to consider that the alg treats the whole numbers
// as irrelevant. It only deals with SET bits!!!
// let's say our array elemts are 1bit long:  1 1 0 1
// we will say:
//  - 'twos' is 1 (It hold two 1's) if 'ones' is 1 and new number is 1 => twos = twos || (ones && new)
//    this happens only if 'twos' was already one or (new is 1 and 'ones' is 1 - aka 1 is now duplicated)
//  - by using xor for ones, we ensure that pairs of 1's cancel each other
//  - if twos and ones are 1, we collectively kill this INDIVIDUAL SET bit
// so using the rules above: 1 1 0 1 => 0; 1 1 0 0 => 0; 1 0 0 0 => 0; 1 => 1; 1 1 1 1 => 1
// The alg resolves the number to be returned by applying the "3 rules above INDEPENDENTLY for each one of the 31 bits of 
// the array elements"
// Seen like this, the alg is very close from getUniqueElement1. Now the collection of bits (aka the number) is processed 
// one by one, instead of processing all of the same bits for the whole array, then the next bits, ... (getUniqueElement1' alg) 
int getUniqueElement2(int *arr, int arrSize){

  int ones = 0, twos = 0, threes = 0;

  for(int i = 0 ; i < arrSize ; i++){
    twos = twos | (ones & arr[i]);
    ones = ones ^ arr[i];
    threes = ones & twos;

    ones = ones & ~threes;
    twos = twos & ~threes;
  }

  return ones;
}


// Since everything is repeated 3 times
// get sum of array as Sa
// get 3 * sum of individula elemnts Sc
// missing element is (Sc - Sa) / 2
// requires O(n) space, #uniques element is 
// approximately n/3 => O(n)
//
// std::set is commonly implemented as a red-black binary search tree. 
// Insertion on this data structure has a worst-case of O(log(n)) 
// complexity, as the tree is kept balanced
// time complexity O(n log(n) + n) insertions + sum calculations
int getUniqueElement3(int *arr, int arrSize){
  set<int> s(arr, arr + arrSize);
  int arrSum = accumulate(arr, arr + arrSize, 0);
  int setSum = accumulate(s.begin(), s.end(), 0);
  return (3*setSum - arrSum)/2;
}






// https://www.geeksforgeeks.org/find-the-element-that-appears-once/
int main(int argc, char **argv, char **envp){

  int arrSize, *arr, exp;


  arrSize = 10; arr = new int[arrSize]{12, 1, 12, 3, 12, 1, 1, 2, 3, 3}; exp = 2; 
  assert(getUniqueElement1(arr, arrSize) == exp);
  assert(getUniqueElement2(arr, arrSize) == exp);
  assert(getUniqueElement3(arr, arrSize) == exp);


  arrSize = 7; arr = new int[arrSize]{10, 20, 10, 30, 10, 30, 30}; exp = 20; 
  assert(getUniqueElement1(arr, arrSize) == exp);
  assert(getUniqueElement2(arr, arrSize) == exp);
  assert(getUniqueElement3(arr, arrSize) == exp);

  arrSize = 4; arr = new int[arrSize]{6, 7, 6, 6}; exp = 7; 
  assert(getUniqueElement1(arr, arrSize) == exp);
  assert(getUniqueElement2(arr, arrSize) == exp);
  assert(getUniqueElement3(arr, arrSize) == exp);


  cout << "\nProgram Exited Successfully";
  return 0;
}
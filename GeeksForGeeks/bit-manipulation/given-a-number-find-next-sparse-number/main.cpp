#include <bits/stdc++.h>

using namespace std;


// A number is Sparse if there are no two adjacent 1s in its binary representation. 
// For example 5 (binary representation: 101) is sparse, but 6 (binary representation: 110) is not sparse.
// Given a number x, find the smallest Sparse number which greater than or equal to x.
int getNextSparseNumber(int num){
  
  int nBits = 8 * sizeof(num);
  unsigned int pattern_00 = 0b0011, pattern_01 = 0b1011;
  int mask = INT_MIN; // INT_MIN = 1000 0000   0000 0000   0000 0000   0000 0000  (-2147483647 - 1)
  
  pattern_00 = pattern_00 << (nBits - 4);
  pattern_01 = pattern_01 << (nBits - 4);
  mask = mask >> 3; 

  // Edge cases
  if((num & (pattern_00 << 2)) == (pattern_00 << 2)) return 0;
  if((num & (pattern_00 << 1)) == (pattern_00 << 1)) return INT_MIN;

  // Algorithm: Looking for portion of num that matches pattern ....11....
  while((pattern_00 != 0) && ((num & pattern_00) != pattern_00)){ 
    pattern_00 = pattern_00 >> 1;
    pattern_01 = pattern_01 >> 1;
    mask = mask >> 1;
  }

  // We have found a mathc
  if((num & pattern_00) == pattern_00){

    // if num also matches ....X1011.... (we also know the X can only be a 0)
    // we needs to kill everything below the X, other wise kill everything strating by 11 going down
    mask = mask << ((num & pattern_01) == pattern_01) ? 4 : 2; // Adjust mask to start above match

    // Mutate num into next sparse number
    num = num & mask;       // kill everything starting at the match and going to lsb
    num = num | (0 - mask); // Set bit: if mask is '1110 0000' then (0 - mask) is '0010 0000'

  }

  return num;
}



// https://www.geeksforgeeks.org/given-a-number-find-next-sparse-number
int main(int argc, char **argv, char **envp){

  int num, exp; 
  

  num = 6, exp = 8;
  assert(getNextSparseNumber(num) == exp);
  
  num = 4, exp = 4;
  assert(getNextSparseNumber(num) == exp);
  
  num = 38, exp = 40;
  assert(getNextSparseNumber(num) == exp);
    
  num = 44, exp = 64;
  assert(getNextSparseNumber(num) == exp);




  cout << "\nProgram Exited Successfully";
  return 0;
}
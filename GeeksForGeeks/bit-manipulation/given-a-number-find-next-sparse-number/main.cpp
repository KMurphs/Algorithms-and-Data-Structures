#include <bits/stdc++.h>

using namespace std;


// A number is Sparse if there are no two adjacent 1s in its binary representation. 
// For example 5 (binary representation: 101) is sparse, but 6 (binary representation: 110) is not sparse.
// Given a number x, find the smallest Sparse number which greater than or equal to x.
int getNextSparseNumber(int num){
  
  int nBits = 8 * sizeof(num);
  unsigned int pattern_00 = 3, pattern_01 = 11;
  int mask;//, setter;

  assert(INT_MIN == (1 << (nBits - 1)));
  assert((INT_MIN >> 7) + (1 << (nBits - 7 - 1)) == 0);
  assert((INT_MIN >> 9) + (1 << (nBits - 10)) == 0);
  // Since relations above is true, we can avoid keeping track of setter
  // if i is not 1: (INT_MIN >> i) + (1 << (nBits - i)) == 0
  // so setter = 0 - mask
  mask = INT_MIN >> 1; //setter = 1 << (nBits - 2) or setter = 0 - mask;
  // setter = 1 << (nBits - 2);
  
  

  pattern_00 = pattern_00 << (nBits - 4);
  pattern_01 = pattern_01 << (nBits - 4);
  mask = mask >> 2; //setter = 1 << (nBits - 2) or setter = 0 - mask;
  //setter = setter >> 2;

  if((num & (pattern_00 << 2)) == (pattern_00 << 2)) return 0;
  if((num & (pattern_00 << 1)) == (pattern_00 << 1)) return INT_MIN;



  while((pattern_00 != 0) && ((num & pattern_00) != pattern_00)){ 
    pattern_00 = pattern_00 >> 1;
    pattern_01 = pattern_01 >> 1;
    mask = mask >> 1;
    //setter = setter >> 1;
  }

  if((num & pattern_00) == pattern_00){

    mask = mask << 2;//, setter = setter << 2;
    if((num & pattern_01) == pattern_01) mask = mask << 2;//, setter = setter << 2;

    num = num & mask;
    num = num | (0 - mask); // if mask is '1110 0000' then (0 - mask) is '0010 0000'
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
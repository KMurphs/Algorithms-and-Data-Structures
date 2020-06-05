#include <bits/stdc++.h>

using namespace std;


// Given an integer array of n integers, find sum of bit differences in all pairs that can be formed from array elements. 
// Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y.
// For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers). 
string toBinary(int num){
  
  string res = "";

  unsigned int mask = 1 << (8*sizeof(num) - 1);
  while(((num & mask) == 0) && (mask != 0)) {
    mask = mask >> 1;
  }

  if(num & mask){
    while(mask != 0){
      res = res + (num & mask ? "1" : "0");
      mask = mask >> 1;
    }
  }else{
    res = "0";
  }

  return res;
}



// https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
int main(int argc, char **argv, char **envp){

  assert(toBinary(15) == "1111");
  assert(toBinary(0) == "0");
  assert(toBinary(0b11101001) == "11101001");

  cout << "\nProgram Exited Successfully";
  return 0;
}
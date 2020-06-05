#include <bits/stdc++.h>

using namespace std;


// Given an unsigned integer, swap all odd bits with even bits. For example, if the given number is 23 (00010111), 
// it should be converted to 43 (00101011). Every even position bit is swapped with adjacent bit on right side 
// (even position bits are highlighted in binary representation of 23), and every odd position bit is swapped 
// with adjacent on left side.
int swapOddAndEvenBits(int num){
  return (num << 1) & 0xAAAAAAAA | (num >> 1) & 0x55555555;
}



// https://www.geeksforgeeks.org/swap-all-odd-and-even-bits/
int main(int argc, char **argv, char **envp){


  assert(swapOddAndEvenBits(0x1111) == 0x2222);
  assert(swapOddAndEvenBits(0x2222) == 0x1111);


  cout << "\nProgram Exited Successfully";
  return 0;
}
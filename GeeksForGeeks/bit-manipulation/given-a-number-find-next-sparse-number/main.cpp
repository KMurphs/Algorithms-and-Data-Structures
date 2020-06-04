#include <bits/stdc++.h>

using namespace std;



int lRotate(unsigned int num, int rotations){
  

  rotations = rotations % (8*sizeof(num)); // optimization. Can only do a max of 31 shifts 5%2=1, -5%2=-1
  if(rotations < 0) rotations = rotations + (8*sizeof(num)); // less line of code. rotation -1 is rotation +31

  while(rotations > 0){
    num = (num << 1) | (bool)(num & INT_MIN);
    rotations--;
  }


  return num;
}



// https://www.geeksforgeeks.org/rotate-bits-of-an-integer/
int main(int argc, char **argv, char **envp){

  int num, exp; 
  

  assert(lRotate(151, 0) == 151);

  assert(lRotate(1, 1) == 2);
  assert(lRotate(2, 1) == 4);
  assert(lRotate(4, 2) == 16);
  assert(lRotate(INT_MIN, 2) == 2);
  assert(lRotate(INT_MIN >> 1, 4) == 12);
  
  assert(lRotate(1, -1) == INT_MIN);
  assert(lRotate(2, -1) == 1);
  assert(lRotate(8, -2) == 2);
  assert(lRotate(INT_MIN, -2) == (0x20 << (8 * (sizeof(int) - 1))));
  assert(lRotate(INT_MIN >> 1, -4) == (12 << (8 * (sizeof(int) - 1))));




  cout << "\nProgram Exited Successfully";
  return 0;
}
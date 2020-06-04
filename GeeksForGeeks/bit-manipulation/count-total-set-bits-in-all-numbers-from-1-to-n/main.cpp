#include <bits/stdc++.h>

using namespace std;



int countSetBitUnderN(int N){

  int powerOf2 = 1, count = 0, div, rem;
  N = N + 1;

  do{
    div = (N / (powerOf2 << 1)) * powerOf2;
    rem = (N % (powerOf2 << 1)) - powerOf2;
    count = count + div + (rem > 0 ? rem : 0);
    powerOf2 = powerOf2 << 1;
  }while(div != 0);

  return count;
}



// https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
int main(int argc, char **argv, char **envp){



  assert(countSetBitUnderN(9) == 15);
  assert(countSetBitUnderN(8) == 13);
  assert(countSetBitUnderN(3) == 4);
  assert(countSetBitUnderN(6) == 9);
  assert(countSetBitUnderN(7) == 12);

  cout << "\nProgram Exited Successfully";
  return 0;
}
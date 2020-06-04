#include <bits/stdc++.h>

using namespace std;



int flipDistance1(int a, int b){

  int distSpace = a ^ b, distCount = 0;
  while(distSpace != 0){
    distCount = distCount + (distSpace & 1);
    distSpace = distSpace >> 1;
  }
  return distCount;
}
int flipDistance2(int a, int b){

  int distSpace = a ^ b, distCount = 0;
  while(distSpace != 0){
    distCount++;
    distSpace = distSpace & (distSpace - 1);
  }
  return distCount;
}


// https://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
int main(int argc, char **argv, char **envp){

  int num, exp; 
  

  assert(flipDistance1(10, 20) == 4);
  assert(flipDistance1(7, 10) == 3);

  assert(flipDistance2(10, 20) == 4);
  assert(flipDistance2(7, 10) == 3);

  cout << "\nProgram Exited Successfully";
  return 0;
}
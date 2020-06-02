#include <bits/stdc++.h>


using namespace std;

int *findPairClosestToSum(int arr[], int arrSize, int sum){

  int *sol = new int[2]{0, 0};

  int l = 0, r = arrSize - 1, bestSum = INT_MAX, currSum;
  while(l < r){
    
    currSum = arr[r] + arr[l];
    if(abs(currSum - sum) < abs(bestSum - sum)) {
      bestSum = currSum;
      sol[0] = arr[l];
      sol[1] = arr[r];
    }

    if(currSum == sum) return sol;
    if(currSum > sum) r--;
    if(currSum < sum) l++;

  }

  return sol;
}



int main(){
  #define SIZE 5

  int *arr, sum, size, *exp, *res;


  size = 6, arr = new int[size]{ 10, 22, 28, 29, 30, 40 }, sum = 54, exp = new int[2]{ 22, 30 };
  res = findPairClosestToSum(arr, size, sum);
  for(int i = 0; i < 2; i++)
    assert(res[i] == exp[i]);


  size = 5, arr = new int[size]{ 1, 3, 4, 7, 10 }, sum = 15, exp = new int[2]{ 4, 10 };
  res = findPairClosestToSum(arr, size, sum);
  for(int i = 0; i < 2; i++)
    assert(res[i] == exp[i]);


  cout << "\n\n\nProgram exited successfully..." << endl;
  return 0;
}
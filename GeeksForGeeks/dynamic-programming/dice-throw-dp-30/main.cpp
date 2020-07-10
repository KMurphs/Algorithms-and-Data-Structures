#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


int countDiceThrowsUtil(int n, int m, int target, int curr, int nDice, string choices){

  if(nDice == n + 1 && curr == target) cout << choices << endl;
  if(nDice == n + 1 && curr == target) return 1;
  
  
  if(curr >= target) cout << "\t" << choices << endl;
  if(curr >= target) return 0;
  if(nDice >= n + 1) cout << "\t\t" << choices << endl;
  if(nDice >= n + 1) return 0;


  int count = 0;
  for (int i = 1; i <= m; i++){
    count += countDiceThrowsUtil(n, m, target, curr + i, nDice + 1, choices + to_string(i) + ", ");
  }
  return count;
}


int countDiceThrows(int n, int m, int target){
  int *arr = new int[n];
  for (int i = 0; i < n; i++){
    arr[i] = 1;
  }

  return countDiceThrowsUtil(n, m, target, 0, 1, "");
}






// https://www.geeksforgeeks.org/dice-throw-dp-30/
int main(){

    int n, m, target, exp;

    n = 4, m = 2, target = 1, exp = 0;
    assert(countDiceThrows(n, m, target) == exp);


    n = 2, m = 2, target = 3, exp = 2;
    assert(countDiceThrows(n, m, target) == exp);


    n = 6, m = 3, target = 8, exp = 21;
    assert(countDiceThrows(n, m, target) == exp);


    n = 4, m = 2, target = 5, exp = 4;
    assert(countDiceThrows(n, m, target) == exp);


    n = 4, m = 3, target = 5, exp = 4;
    assert(countDiceThrows(n, m, target) == exp);


    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
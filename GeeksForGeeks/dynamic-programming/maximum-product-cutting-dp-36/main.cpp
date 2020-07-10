#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;



int wordBreakUtil(int n, int start, int pos){

  if(pos - start >= n) return 0;
  if(start == n) return 1;
  if(pos > n) return 0;

  return max(
    wordBreakUtil(n, start, pos + 1),
    (pos - start) * wordBreakUtil(n, pos, pos + 1)
  );
}

int maxProdCutting(int n){
  return wordBreakUtil(n, 0, 1);
}








// https://www.geeksforgeeks.org/maximum-product-cutting-dp-36/
int main(){

    int n, exp;

    n = 2, exp = 1;
    assert(maxProdCutting(n) == exp);

    n = 3, exp = 2;
    assert(maxProdCutting(n) == exp);

    n = 4, exp = 4;
    assert(maxProdCutting(n) == exp);

    n = 5, exp = 6;
    assert(maxProdCutting(n) == exp);

    n = 10, exp = 36;
    assert(maxProdCutting(n) == exp);


    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
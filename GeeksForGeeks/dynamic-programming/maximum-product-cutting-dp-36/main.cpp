#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// 1. combinatorial solution
// 2. recursive brute force
// 3. contained recursive state
// 4. overlapping subproblems
// 5. ordering on dimensions (start and pos)
// Note: exponential brute force => O(2^n)

int maxProdCuttingUtil(int n, int start, int pos){

  if(pos - start >= n) return 0;
  if(start == n) return 1;
  if(pos > n) return 0;

  return max(
    maxProdCuttingUtil(n, start, pos + 1),
    (pos - start) * maxProdCuttingUtil(n, pos, pos + 1)
  );
}



int maxProdCuttingUtil2(int n){

  if(n == 0) return 1;

  int maxSol = INT_MIN;
  for(int i = 1 ; i < n ; i++ ){

    int tmpSol = max(
      i * maxProdCuttingUtil2(n - i),
      i * (n - i)
    );

    if(tmpSol > maxSol){
      maxSol = tmpSol;
    }

  }

  return maxSol;
}

int maxProdCutting(int n){
  return maxProdCuttingUtil2(n);
  // return maxProdCuttingUtil(n, 0, 1);
}


int maxProdCuttingDP(int n){

  int *dp = new int[n + 1];
  memset(dp, 0, sizeof(int) * (n + 1));

  dp[0] = 1;
  dp[1] = 1;

  for(int i = 2 ; i <= n ; i++){
    for(int j = 1 ; j < i ; j++ ){

      dp[i] = max(dp[i],
        max(
          j * dp[i - j],
          j * (i - j)
        )
      );

    }
  }

  return dp[n];
}





// https://www.geeksforgeeks.org/maximum-product-cutting-dp-36/
int main(){

    int n, exp;

    n = 2, exp = 1;
    assert(maxProdCutting(n) == exp);
    assert(maxProdCuttingDP(n) == exp);

    n = 3, exp = 2;
    assert(maxProdCutting(n) == exp);
    assert(maxProdCuttingDP(n) == exp);

    n = 4, exp = 4;
    assert(maxProdCutting(n) == exp);
    assert(maxProdCuttingDP(n) == exp);

    n = 5, exp = 6;
    assert(maxProdCutting(n) == exp);
    assert(maxProdCuttingDP(n) == exp);

    n = 10, exp = 36;
    assert(maxProdCutting(n) == exp);
    assert(maxProdCuttingDP(n) == exp);


    for(int i = 1 ; i <= 10 ; i++){
      cout << maxProdCutting(i) << endl;
    }

    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
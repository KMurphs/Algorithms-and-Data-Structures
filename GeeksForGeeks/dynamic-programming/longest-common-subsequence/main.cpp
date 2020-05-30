#include <bits/stdc++.h>
using namespace std;

// http://www.parashift.com/c++-faq/

int lcs(char x[], char y[], int xLen, int yLen){

  vector<vector<int>> dp;
  for(int i = 0 ; i <= xLen; i++){
    vector<int> tmp;
    for(int j = 0; j <= yLen; j++)
      tmp.push_back(0);
    dp.push_back(tmp);
  }


  for(int i = 0 ; i <= xLen; i++){
    for(int j = 0; j <= yLen; j++){
      if(i == 0 || j == 0) 
        dp[i][j] = 0;
      else
        if(x[i - 1] == y[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  
  return dp[xLen][yLen];
}


int main(){

    char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB";  
      
    int m = strlen(X);  
    int n = strlen(Y);  

    int res = lcs( X, Y, m, n );
    cout << "Length of LCS is "<< res;  
    assert(res == 4);

    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
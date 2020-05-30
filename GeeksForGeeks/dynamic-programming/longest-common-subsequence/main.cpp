#include <bits/stdc++.h>
using namespace std;

// http://www.parashift.com/c++-faq/

int lcs(char x[], char y[], int xLen, int yLen){

  int dp[xLen + 1][yLen + 1];

  for(int i = 0 ; i <= xLen; i++)
    for(int j = 0; j <= yLen; j++){
      if(i == 0 || j == 0) 
        dp[i][j] = 0;
      else
        if(x[i - 1] == y[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }

  return dp[xLen][yLen];
}

// int lcs(char y[], char x[], int yLen, int xLen){

//   int dp[xLen + 1][yLen + 1];

//   for(int i = 0 ; i <= xLen; i++)
//     for(int j = 0; j <= yLen; j++){
//       if(i == 0 || j == 0) 
//         dp[i][j] = 0;
//       else{
//         printf("\n\nProcessing: (%c(%d), %c(%d)) - %d", x[i - 1], i, y[j - 1], j, dp[i][j]);
//         dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (x[i - 1] == y[j - 1] ? 1 : 0);
//         printf("\nSides: %d, %d - Max: %d - Current: %d", dp[i - 1][j], dp[i][j - 1], max(dp[i - 1][j], dp[i][j - 1]), dp[i][j]);
//       }
        
//     }

//   return dp[xLen][yLen];
// }
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
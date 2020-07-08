#include <bits/stdc++.h>

using namespace std;





// we have a combinatorial brute force solution with optimal substructure property
// and overlapping problems (whether we insert, or leave alone, we still want to reduce)
// the tokens after the current point twice (for each case))
// O(2^n) each call generate two sub problems, while the size of the subproblems
// decrement by 1 from n to 1
string buildShortestSuperSeq(string s1, string s2, int i1 = 0, int i2 = 0){

  if(i2 == s2.size()) return s1;
  if(i1 == s1.size()) return s1 + s2.substr(i2);


  // A match, be greedy (don't go through the lines after the if statement)
  // As a matter of fact, if it's match why would i:
  //   1. Add the same letter again
  //   2. Pass the match and attempt to get a better solution in the future  
  if(s1[i1] == s2[i2]){ 
    return buildShortestSuperSeq(s1, s2, i1 + 1, i2 + 1);
  }


  string res1 = buildShortestSuperSeq((i1 > 0 ? s1.substr(0, i1) : "") + s2[i2] + s1.substr(i1), s2, i1 + 1, i2 + 1); // insert
  string res2 = buildShortestSuperSeq(s1, s2, i1 + 1, i2); // leave alone
  

  return res1.size() < res2.size() ? res1 : res2;
}



string buildShortestSuperSeqDP(string s1, string s2){

  int **dp = new int*[s1.size() + 1];
  for(int i = 0 ; i < s1.size() + 1 ; i++){
    dp[i] = new int[s2.size() + 1];
    memset(dp[i], 0, sizeof(int) * (s2.size() + 1));
  }


  for(int i = 0 ; i < s1.size() + 1 ; i++){
    dp[i][0] = i;
  }
  for(int i = 0 ; i < s2.size() + 1 ; i++){
    dp[0][i] = i;
  }


  for(int i = 1 ; i < s1.size() + 1 ; i++){
    for(int j = 1 ; j < s2.size() + 1 ; j++){
      if(s1[i - 1] == s2[j - 1])
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);   // If match the longest neighbour becomes the answer
      else 
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1; // If not match, the shortest neighbour is promoted
    }
  }


  cout << dp[s1.size()][s2.size()] << endl;

  return *new string(dp[s1.size()][s2.size()], 'x');
}




// https://www.geeksforgeeks.org/shortest-common-supersequence/
int main(int argc, char **argv, char **envp){

  string str1, str2, res;
  int exp;



  str1 = "geek", str2 = "eke", exp = 5;
  res = buildShortestSuperSeq(str1, str2);
  cout << res << endl;
  assert(res.size() == exp);
  res = buildShortestSuperSeqDP(str1, str2);
  assert(res.size() == exp);



  str1 = "AGT", str2 = "XT", exp = 4;
  res = buildShortestSuperSeq(str1, str2);
  cout << res << endl;
  assert(res.size() == exp);
  res = buildShortestSuperSeqDP(str1, str2);
  assert(res.size() == exp);



  str1 = "AGGTAB", str2 = "GXTXAYB", exp = 9;
  res = buildShortestSuperSeq(str1, str2);
  cout << res << endl;
  assert(res.size() == exp);
  res = buildShortestSuperSeqDP(str1, str2);
  assert(res.size() == exp);



  cout << "\nProgram Exited successfully";
  return 0;
}
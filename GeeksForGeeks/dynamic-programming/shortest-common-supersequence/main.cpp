#include <bits/stdc++.h>

using namespace std;






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




// https://www.geeksforgeeks.org/shortest-common-supersequence/
int main(int argc, char **argv, char **envp){

  string str1, str2, res;
  int exp;



  str1 = "geek", str2 = "eke", exp = 5;
  res = buildShortestSuperSeq(str1, str2);
  cout << res << endl;
  assert(res.size() == exp);


  str1 = "AGT", str2 = "XT", exp = 4;
  res = buildShortestSuperSeq(str1, str2);
  cout << res << endl;
  assert(res.size() == exp);


  str1 = "AGGTAB", str2 = "GXTXAYB", exp = 9;
  res = buildShortestSuperSeq(str1, str2);
  cout << res << endl;
  assert(res.size() == exp);


  cout << "\nProgram Exited successfully";
  return 0;
}
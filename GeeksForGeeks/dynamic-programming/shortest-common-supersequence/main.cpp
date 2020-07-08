#include <bits/stdc++.h>

using namespace std;


string solve(string s1, string s2, int i1, int i2){

  if(i2 + 1 == s2.size()) return s1;
  if(i1 + 1 == s1.size()) return s1 + s2.substr(i2 + 1);

  if(s1[i1 + 1] == s2[i2 + 1]){
    return solve(s1, s2, i1 + 1, i2 + 1);
  }

  string res1 = solve((i1 >= 0 ? s1.substr(0, i1 + 1) : "") + s2[i2 + 1] + s1.substr(i1 + 1), s2, i1 + 1, i2 + 1); // insert
  string res2 = solve(s1, s2, i1 + 1, i2); // leave alone
  
  return res1.size() < res2.size() ? res1 : res2;
}




string buildShortestSuperSeq(string s1, string s2){
  return solve(s1, s2, -1, -1);
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
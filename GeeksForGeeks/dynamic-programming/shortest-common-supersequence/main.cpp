#include <bits/stdc++.h>

using namespace std;


string solve(string s1, string s2, int i1, int i2){

  cout << "        ***" << endl;
  cout << s1 << "\t" << s2 << endl;

  if(i1 == s1.size() && i2 == s2.size()) return s1;
  if(i1 == s1.size()) return s1 + s2.substr(i2);
  if(i2 == s2.size()) return s1;

  string res1 = "", res2 = "", res3 = "";

  res1 = solve((i1 > 0 ? s1.substr(0, i1) : "") + s2[i2] + s1.substr(i1), s2, i1 + 1, i2 + 1); // insert
  // res1 = solve(s1.substr(0, i1 + 1) + s2[i2] + s1.substr(i1 + 1), s2, i1 + 1, i2 + 1); // insert
  res2 = solve(s1, s2, i1 + 1, i2); // leave alone



  cout << res1 << endl;
  cout << res2 << endl;
  

  if(s1[i1] == s2[i2]){
    res3 = solve(s1, s2, i1 + 1, i2 + 1);
    cout << res3 << endl;
    if(res3.size() < res1.size() && res3.size() < res2.size())
      return res3;
  }
  
  return res1.size() < res2.size() ? res1 : res2;
}




string buildShortestSuperSeq(string s1, string s2){
  return solve(s1, s2, 0, 0);
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
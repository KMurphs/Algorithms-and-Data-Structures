#include <bits/stdc++.h>
using namespace std;






bool matchToPatternUtil(map<char, string>& mp, string inStr, int n, int i, string pattern, int m, int j){

  if(i == n && j == m) return true;
  if(i == n || j == m) return false;



  if(mp.find(pattern[j]) != mp.end()){
    
    string potMatch = inStr.substr(i, mp[pattern[j]].size());
    if(potMatch.compare(mp[pattern[j]]))
      return false;

    return matchToPatternUtil(mp, inStr, n, i + mp[pattern[j]].size(), pattern, m, j + 1);
  }



  for(int len = 1 ; len <= n - i ; len++){
    mp[pattern[j]] = inStr.substr(i, len);
    if(matchToPatternUtil(mp, inStr, n, i + len, pattern, m, j + 1))
      return true;
    mp.erase(pattern[j]);
  }


  return false;
}





bool matchToPattern(string inStr, int n, string pattern, int m){

  map<char, string> mp = *new map<char, string>();
  bool res = matchToPatternUtil(mp, inStr, n, 0, pattern, m, 0);


  for(int i = 0 ; i < m ; i++){
    cout << mp[pattern[i]] << ", ";
  }
  cout << endl;


  return res;
}




// https://www.geeksforgeeks.org/match-a-pattern-and-string-without-using-regular-expressions/
int main(int argc, char **argv, char **envp){

  string str, pat;
  char *inStr, *inPat;



  str = "GraphTreesGraph", pat = "aba";
  assert(matchToPattern(str, str.size(), pat, pat.size()) == true);
  // inStr = "GraphGraphGraph", pattern = "aaa", inStrLength = 15, patternLength = 3;
  // assert(matchToPattern(inStr, inStrLength, pattern, patternLength) == true);
  // inStr = "GeeksforGeeks", pattern = "GfG", inStrLength = 13, patternLength = 3;
  // assert(matchToPattern(inStr, inStrLength, pattern, patternLength) == true);
  // inStr = "GeeksforGeeks", pattern = "GG", inStrLength = 13, patternLength = 2;
  // assert(matchToPattern(inStr, inStrLength, pattern, patternLength) == true);


  cout << "Program is exiting..." << endl; 
  return 0; 
}
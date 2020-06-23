#include <bits/stdc++.h>
using namespace std;


int fact(int m){
  if(m <= 1) return 1;
  return m * fact(m - 1);
}



void dfsUtil(vector<string>& sols, const string str, bool *visited, string currChars, int currPos, int src){

  if(currPos >= str.size()){
    sols.push_back(*new string(currChars));
    for(vector<string>::iterator it = sols.begin() ; it != sols.end() ; ++it)
      cout << *it << "  ";
    cout << endl;
    return;
  }
  


  for(int i = 0 ; i < str.size() ; i++){
    if(!visited[i]){
      currChars[currPos] = str[i];
      visited[i] = 1;
      dfsUtil(sols, str, visited, currChars, currPos + 1, i);
      visited[i] = 0;
    }
  }

}




vector<string> getPermutations(const string str){

  bool *visited = new bool[str.size()];
  memset(visited, 0, sizeof(bool) * str.size());


  vector<string> sols = vector<string>();
  string currChars = str;


  for(int i = 0 ; i < str.size() ; i++){
    visited[i] = 1;
    currChars[0] = str[i];
    dfsUtil(sols, str, visited, currChars, 1, i);
    visited[i] = 0;
  }

  // cout << sols.size() << endl;
  return sols;
}



// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
int main(){

    vector<string> perms;
    string str;
    
    assert(fact(3) == 6);

    str = "ABC";
    perms = getPermutations(str);
    assert(perms.size() == fact(str.size()));



    cout << "Program is exiting..." << endl; 
    return 0; 
}
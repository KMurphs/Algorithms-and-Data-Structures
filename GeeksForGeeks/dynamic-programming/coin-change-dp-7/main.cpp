#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;



bool wordBreakUtil(set<string> dict, string str, int start, int end){

  if(start == str.size()) return true;
  if(end   >= str.size()) return false;

  set<string>::iterator it; 
  it = dict.find(str.substr(start, end - start + 1)); 

  if(it != dict.end()){
    return wordBreakUtil(dict, str, end + 1, end + 1);
  }

  return wordBreakUtil(dict, str, start, end + 1);
}

bool wordBreak(set<string> dict, string str){
  return wordBreakUtil(dict, str, 0, 0);
}








// https://www.geeksforgeeks.org/word-break-problem-dp-32/
int main(){


    // #include <unordered_set>
    // unordered_set<int> dict;


    set<string> dict;
    dict.insert("mobile");
    dict.insert("samsung");
    dict.insert("sam");
    dict.insert("sung");
    dict.insert("man");
    dict.insert("mango");
    dict.insert("icecream");
    dict.insert("and");
    dict.insert("go");
    dict.insert("i");
    dict.insert("like");
    dict.insert("ice");
    dict.insert("cream");



    string str;
    bool exp;

    str = "ilikesamsung", exp = 1;
    assert(wordBreak(dict, str) == exp);
    str = "iiiiiiii", exp = 1;
    assert(wordBreak(dict, str) == exp);
    str = "", exp = 1;
    assert(wordBreak(dict, str) == exp);
    str = "ilikelikeimangoiii", exp = 1;
    assert(wordBreak(dict, str) == exp);
    str = "samsungandmango", exp = 1;
    assert(wordBreak(dict, str) == exp);
    str = "samsungandmangok", exp = 0;
    assert(wordBreak(dict, str) == exp);


    cout << "\n\nProgram is exiting..." << endl; 
    return 0; 
}
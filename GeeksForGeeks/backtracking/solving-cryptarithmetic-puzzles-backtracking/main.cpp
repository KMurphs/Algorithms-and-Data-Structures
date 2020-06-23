#include <bits/stdc++.h>
using namespace std;


#define ALPHABET_SIZE 26

bool backTracking(map<char, int>& mp, int *digs, string str1, string str2, string str3){


  map<char, int>::iterator itr = mp.begin();
  while(itr != mp.end() && itr->second != -1)
    ++itr;




  if(itr == mp.end()){
    int a, b, c, carry;

    carry = 0;
    for(int i = 0 ; i < str3.size() ; i++){
      a = i < str1.size() ? mp[str1[str1.size() - i - 1]] : 0;
      b = i < str2.size() ? mp[str2[str2.size() - i - 1]] : 0;
      c = a + b + carry;
      carry = c / 10;
      c = c % 10;

      if(mp[str3[str3.size() - i - 1]] != c)
        return false;
    }

    for(map<char, int>::iterator it = mp.begin() ; it != mp.end() ; ++it)
      cout << it->first << " " << it->second << endl;
    cout << endl;

    return true;
  }
  





  for(int i = 0 ; i < 10 ; ++i){

    if(digs[i] == 1){

      digs[i] = 0;
      mp[itr->first] = i;
      if(backTracking(mp, digs, str1, str2, str3))
        return true;
      mp[itr->first] = -1;
      digs[i] = 1;

    }

  }


  return false;
}



bool solve(string str1, string str2, string str3){

  int *digs = new int[10];
  for(int i = 0 ; i < 10 ; i++)
    digs[i] = 1;

  map<char, int> mp = *new map<char, int>();

  char *alphabet = new char[ALPHABET_SIZE];
  memset(alphabet, 0, sizeof(char) * ALPHABET_SIZE);
  for(int i = 0 ; i < str1.size() ; i++) alphabet[str1[i] - 'A'] = 1;
  for(int i = 0 ; i < str2.size() ; i++) alphabet[str2[i] - 'A'] = 1;
  for(int i = 0 ; i < str3.size() ; i++) alphabet[str3[i] - 'A'] = 1;

  for(int i = 0 ; i < ALPHABET_SIZE ; i++) 
    if(alphabet[i] != 0)
      mp[i + 'A'] = -1;

  return backTracking(mp, digs, str1, str2, str3);
}

// https://www.geeksforgeeks.org/solving-cryptarithmetic-puzzles-backtracking-8/
int main(){


    string str1, str2, str3;
    bool isValid;
    


    str1 = "SEND", str2 = "MORE", str3 = "MONEY";
    assert(solve(str1, str2, str3));



    cout << "Program is exiting..." << endl; 
    return 0; 
}
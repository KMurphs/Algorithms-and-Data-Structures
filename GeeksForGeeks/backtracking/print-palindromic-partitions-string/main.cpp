#include <bits/stdc++.h>

using namespace std;



bool isPalyndrom(string str, int l, int r){
  while(l < r){
    if(!(str[l++] == str[r--]))
      return false;
  }
  return true;
}






void generatePalyndromPartitions(vector<vector<string>>& sols, string str, int pos, vector<string>& curr){

  if(pos >= str.size()){
    sols.push_back(*new vector<string>(curr));
    return;
  }


  for(int end = pos + 1 ; end <= str.size() ; end++){
    if(isPalyndrom(str, pos, end - 1)){
      curr.push_back(str.substr(pos, end - pos));
      generatePalyndromPartitions(sols, str, end, curr);
      curr.pop_back();
    }
  }

}




int printPalyndromicPartitions(string str){

  vector<vector<string>> sols = *new vector<vector<string>>();
  vector<string> curr = *new vector<string>();
  generatePalyndromPartitions(sols, str, 0, curr);

  for(vector<vector<string>>::iterator it1 = sols.begin() ; it1 != sols.end() ; ++it1){
    for(vector<string>::iterator it2 = it1->begin() ; it2 != it1->end() ; ++it2){
      cout << it2->c_str() << "  ";
    }
    cout << endl;
  }

  return sols.size();
}




// https://www.geeksforgeeks.org/print-palindromic-partitions-string/
int main(int argc, char **argv, char **envp){

  string str, exp, res;

  assert(isPalyndrom("a", 0, 0));
  assert(isPalyndrom("aa", 0, 1));
  assert(isPalyndrom("baa", 1, 2));
  assert(isPalyndrom("baba", 1, 3));
  assert(!isPalyndrom("baa", 0, 2));
  assert(!isPalyndrom("bbaa", 1, 2));

  str = "bcc", exp = 2;
  assert(printPalyndromicPartitions(str) == 2);

  str = "geeks", exp = 2;
  assert(printPalyndromicPartitions(str) == 2);

  cout << "Program Exited Successfully";
  return 0;
}
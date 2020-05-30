#include <bits/stdc++.h>
using namespace std;


#define M 3 
#define N 3 

// A given function to check if a given string is present in 
// dictionary. The implementation is naive for simplicity. As 
// per the question dictionary is given to us. 
bool isInDictionary(vector<string> dictionary, string& str) 
{   
    // int n = *(&dictionary + 1) - dictionary; 
    int n = dictionary.size(); 
    // Linearly search all words 
    for (int i = 0; i < n; i++) 
        if (str.compare(dictionary[i]) == 0) 
            return true; 
    return false; 
} 
    // Probably only works with ints
    // https://www.quora.com/What-is-the-equivalent-of-array-length-used-in-Java-in-C++
    // int size = *(&arr + 1) - arr;
    // &arr ==> Pointer to an array of 6 elements.
    //          [See this for difference between &arr
    //           and arr]   
    // (&arr + 1) ==> Address of 6 integers ahead as
    //                pointer type is pointer to array
    //                of 6 integers.
    // *(&arr + 1) ==> Same address as (&arr + 1), but 
    //                 type of pointer is "int *".
    // *(&arr + 1) - arr ==> Since *(&arr + 1) points 
    //                    to the address 6 integers
    //                    ahead of arr, the difference
    //                    between two is 6.          

void dfsUtil(vector<string> dictionary, char boggle[M][N], vector<string>& sols, bool visited[3][3], int x, int y, string currChars){
  
  visited[x][y] = 1;
  currChars = currChars + boggle[x][y];


  if(isInDictionary(dictionary, currChars)){
    sols.push_back(currChars);
    // return;
  }


  for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++)
      if( 
        x + i < M && x + i >= 0 &&
        y + j < N && y + j >= 0 &&
        !visited[x + i][y + j]
      ){
        // currChars.push_back(boggle[x + i][y + j]);
        dfsUtil(dictionary, boggle, sols, visited, x + i, y + j, currChars);
        // currChars.pop_back();
      }

  currChars.erase(currChars.length() - 1);
  visited[x][y] = 0;
}

vector<string> dfs(vector<string> dictionary, char boggle[M][N]){
  vector<string> words;
  string str = ""; 

  bool visited[M][N] = { { false } };


  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      dfsUtil(dictionary, boggle, words, visited, i, j, str);

  return words;
}


int main(){

    vector<string> dictionary = { "GEEKS", "FOR", "QUIZ", "GO" }; 
    char boggle[3][3]   = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};

    vector<string> sols {"GEEKS","QUIZ"};

    vector<string> foundWords = dfs(dictionary, boggle);

    assert(sols.size() == foundWords.size());
    for(int i = 0; i < sols.size(); i++){
      bool found = false;
      for(int j = 0; j < foundWords.size(); j++){
        found = found || sols[i] == foundWords[j];
        if(found) break;
      }
      assert(found);
    }


    cout << "Program is exiting..." << endl; 
    return 0; 
}
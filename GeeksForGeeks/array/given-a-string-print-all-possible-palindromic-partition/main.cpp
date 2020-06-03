#include <bits/stdc++.h>

using namespace std;


void printPartitions(string inStr, int *partitions){
  int i = 0;

  while(i < inStr.size()){
    cout << inStr.substr(i, partitions[i] - i) << " ";
    i = partitions[i];
  }

  cout << endl;
}


bool isPalyndrom(string inStr, int l, int r){
  if(l > r) return false;

  while(l < r){
    if(inStr[l] != inStr[r]) return false;
    l++, r--;
  }

  return true;
}



void printPalyndromicPartitions(string inStr){


  // Build partition. Where start pf partition is index
  // and value at index is the beginning of next partition
  // Initial partition will create groups of 1 character
  int *partitions = new int[inStr.size()];
  for(int i = 0; i < inStr.size(); i++){
    partitions[i] = i + 1;
  }



  bool partitionsHaveMutated = true;
  int curr, next, counter, tmp;
  for(int i = 2; i < inStr.size(); i++){

    // If paritions updated flag is set, print
    if(partitionsHaveMutated) {
      printPartitions(inStr, partitions);
    }
    partitionsHaveMutated = false;




    
    // Process partition groups
    curr = 0;
    while(curr < inStr.size()){


      // Consider groups of length "i"
      next = curr, counter = i;
      while(counter > 0) {
        next = (next > inStr.size() ? inStr.size() : partitions[next]);
        counter--;
      }
      if(next - curr != i) { // If a group has length different than "i" don't process it
        curr = partitions[curr]; 
        continue; 
      }


      // Is current group a palyndrom, if yes update partition and set partitionsChanged Flag
      if(isPalyndrom(inStr, curr, next - 1)){
        partitions[curr] = next;
        partitionsHaveMutated = true;
        curr = next;
      }else{
        // No Change to partitions. Prepare to process the next group in current partition
        curr = partitions[curr];
      }
    }
  }



}




void findPalyndromParts(vector<vector<string>>& parts, vector<string>& currParts, int start, string inStr, int inSize){

  // Backtracking Resolution
  if(start >= inSize){
    parts.push_back(currParts);
  }

  // Backtracking Core
  for(int end = start; end < inSize; end++){
    if(isPalyndrom(inStr, start, end)){
      currParts.push_back(inStr.substr(start, end - start + 1));
      findPalyndromParts(parts, currParts, end + 1, inStr, inSize);
      currParts.pop_back();
    }
  }

}


void printPalyndromicPartitionsBacktracking(string inStr){
  vector<vector<string>> sols;
  vector<string> currSol;
  findPalyndromParts(sols, currSol, 0, inStr, inStr.size());
  
  cout << endl;
  for(int i = 0; i < sols.size(); i++){
    for(int j = 0; j < sols[i].size(); j++){
      cout << sols[i][j] << " ";
    }
    cout << endl;
  }

}





int main(int argc, char **argv, char **envp){


  printPalyndromicPartitions("nitin");
  printPalyndromicPartitions("geeks");

  printPalyndromicPartitionsBacktracking("nitin");
  printPalyndromicPartitionsBacktracking("geeks");

  cout << "Program Exited Successfully";
  return 0;
}
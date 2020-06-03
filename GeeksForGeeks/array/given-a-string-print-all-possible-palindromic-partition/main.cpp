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

  bool isPalyndrom = true;
  while(l < r && isPalyndrom){
    isPalyndrom = isPalyndrom && (inStr[l] == inStr[r]);
    l++, r--;
  }

  return isPalyndrom;
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
    if(partitionsHaveMutated) printPartitions(inStr, partitions);
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




int main(int argc, char **argv, char **envp){


  printPalyndromicPartitions("nitin");
  printPalyndromicPartitions("geeks");

  cout << "Program Exited Successfully";
  return 0;
}
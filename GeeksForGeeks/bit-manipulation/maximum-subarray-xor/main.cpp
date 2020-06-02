#include <bits/stdc++.h>

using namespace std;

struct TLeafData{
  // int startIdx; // StartIdx is 0 for all values stored in trie
  int xorValue, endIdx;
};

struct TrieNode{
  TrieNode *child[2];
  TLeafData leafData;
  TrieNode(){
    child[0] = nullptr;
    child[1] = nullptr;
    leafData.endIdx = -1;
    // leafData.startIdx = -1;
    leafData.xorValue = -1;
  };
};


void insertInTrie(TrieNode *root, int num, int endIdx){
  if(root == nullptr) root = new TrieNode();
  TrieNode *curr = root;
  
  for(int i = 8*sizeof(int) - 1; i >= 0; i--){
    if(num & (1 << i)) {
      if(curr->child[1] == nullptr) curr->child[1] = new TrieNode();
      curr = curr->child[1];
    } else {
      if(curr->child[0] == nullptr) curr->child[0] = new TrieNode();
      curr = curr->child[0];
    }
  }

  curr->leafData.xorValue = num;
  curr->leafData.endIdx = endIdx;
}


TLeafData getMostDifferent(TrieNode *root, int num){
  if(root == nullptr) insertInTrie(root, num, 0);
  TrieNode *curr = root;
  bool currBit;

  for(int i = 8*sizeof(int) - 1; i >= 0; i--){

    currBit = num & (1 << i);
    if(curr->child[!currBit] != nullptr) curr = curr->child[!currBit];
    else curr = curr->child[currBit];

  }

  return curr->leafData;
}


// This logics rely on the fact that xor[0 to i] can be used along xor[0 to n]
// to evaluate xor[i+1, n]
// The trie will hold the aggregated xors as we are iterating through the array
// at each point we will query the trie, for the xor value that's most different
// from the current xor (current xor is 4 (from element 1 to 5), 
// and 3 was present in trie (from element 1 to 3), 
// then resulting xor (from element 4 to 5) would be 7)

// The trie should be initialized with 0, as the most different from the  first 
// element of the array

// So compute running xor
// store in trie
// get most different xor already in trie, runningXor ^ mostDifferent will give max xor 
// of subarray that stop at current index
// take maxXOR as the maximum between current max and this new max
int findMaximumXORLinear(int arr[], int arrSize, int **resSol, int *resSolSize){

  TrieNode *root = new TrieNode();
  insertInTrie(root, 0, -1);
  
  int runningXOR = 0, maxXOR = INT_MIN, maxStart, maxEnd;  
  for(int i = 0; i < arrSize; i++){
    runningXOR = runningXOR ^ arr[i];
    insertInTrie(root, runningXOR, i);

    TLeafData mostDifferent = getMostDifferent(root, runningXOR);
    if(maxXOR < (runningXOR ^ mostDifferent.xorValue)){
      maxXOR = (runningXOR ^ mostDifferent.xorValue);
      maxStart = mostDifferent.endIdx + 1;
      maxEnd = i;
    }
  
  }

  *resSolSize = maxEnd - maxStart + 1;
  *resSol = new int[*resSolSize];
  for(int i = 0; i < *resSolSize; i++){
    (*resSol)[i] = arr[maxStart + i];
  }

  return maxXOR;
}










int findMaximumXOR(int arr[], int arrSize, int **resSol, int *resSolSize){

  int max_i, max_j, max_val = INT_MIN, curr_val;
  for(int i = 0; i < arrSize; i++){
    curr_val = 0;

    for(int j = i; j < arrSize; j++){
      curr_val = curr_val ^ arr[j];
      if(curr_val > max_val) { max_i = i, max_j = j, max_val = curr_val; }
    }

  }


  *resSolSize = max_j - max_i + 1;
  *resSol = new int[*resSolSize];
  for(int i = 0; i < *resSolSize; i++){
    (*resSol)[i] = arr[max_i + i];
  }

  return max_val;
}











int main(int argc, char **argv, char **envp){

  int size, *arr, expVal, expSolSize, *expSol, resVal, resSolSize, *resSol; 
  
  size = 4, arr = new int[size]{1, 2, 3, 4}, expVal = 7, expSolSize = 2, expSol = new int[expSolSize]{3, 4}; 
  resVal = findMaximumXOR(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);
  resVal = findMaximumXORLinear(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);



  resVal = findMaximumXORLinear(arr, size, &resSol, &resSolSize);
  cout << "Max XOR is :" << resVal << endl;



  size = 6, arr = new int[size]{8, 1, 2, 12, 7, 6}, expVal = 15, expSolSize = 3, expSol = new int[expSolSize]{1, 2, 12}; 
  resVal = findMaximumXOR(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);
  resVal = findMaximumXORLinear(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);



  size = 2, arr = new int[size]{4, 6}, expVal = 6, expSolSize = 1, expSol = new int[expSolSize]{6}; 
  resVal = findMaximumXOR(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);
  resVal = findMaximumXORLinear(arr, size, &resSol, &resSolSize);
  assert(resVal == expVal);
  for(int i = 0; i < min(resSolSize, expSolSize); i++)
    assert(resSol[i] == expSol[i]);



  cout << "\nProgram Exited Successfully";
  return 0;
}
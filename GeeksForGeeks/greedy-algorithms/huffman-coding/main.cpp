#include <bits/stdc++.h>

using namespace std;

class TreeNode{

  public:
    char data;
    int freq;
    TreeNode *left, *right;
    TreeNode(char _data, char _freq): data(_data), freq(_freq), left(nullptr), right(nullptr){}
    TreeNode(char _data, char _freq, TreeNode *l, TreeNode *r): data(_data), freq(_freq), left(l), right(r){}
};


class Heap{
  int capacity, size;
  void build(char data[], int freq[], int dataSize){
    //Initialize
    size = dataSize;
    heap = new TreeNode *[capacity];
      
    // Put data in structure - unordered
    buildUtil(data, freq);
      
    // Order data in structure
    for(int i = (size/2) - 1; i >= 0 ; i--) 
      heapify(i);
  }
  void buildUtil(char data[], int freq[]){
    // Coerce size to  capacity
    if(size >= capacity) size = capacity;
    // Throw everything as is in heap array (unordered)
    for(int i = size - 1 ; i >= 0 ; i--){
      heap[i] = new TreeNode(data[i], freq[i]);
    }
  }

  // Will make the heap valid (parent is smaller than any of its children and descendants)
  void heapify(int pos){
    int lChild = 2*pos + 1;
    int rChild = 2*pos + 2;
    int minFam = pos;

    // Look for min in family
    if(lChild < size && heap[lChild]->freq < heap[minFam]->freq) minFam = lChild;
    if(rChild < size && heap[rChild]->freq < heap[minFam]->freq) minFam = rChild;
    
    // Parent was not the min of family, fix it
    if(minFam != pos){
      // Put min of family at pos of parent
      Swap(heap[minFam], heap[pos]);
      // Order everything below the new position of the parent
      // We are still not sure it smaller than everything below it
      heapify(minFam);
    }
  }

  // Swap memory address of two heap nodes
  void Swap(TreeNode *elmt1, TreeNode *elmt2){
    TreeNode tmp = *elmt1;
    *elmt1 = *elmt2;
    *elmt2 = tmp;
  }

  



  public:
    TreeNode **heap;

    Heap(int cap = 100): capacity(cap){}
    Heap(char data[], int freq[], int dataSize, int cap = 100): capacity(cap){
      build(data, freq, dataSize);
    }


    int getSize(){
      return size;
    }

    TreeNode *extractMin(){
      // Swap last element and the min to be extracted (at pos 0)
      Swap(heap[0], heap[--size]);
      // last element is in first position and is not the smallest
      // the heap is not valid, re-heapify it then
      heapify(0);

      // Return last element, that we put aside, the smallest
      return heap[size];
    }

    void insert(TreeNode *newNode){
      if(size + 1 >= capacity) return;

      // Make some space for the extra element as long as 
      // we are within capacity
      size++;

      // Assuming the new node's freq is less than most-bottom-right parent
      // bring down parent since new node could be parent of the whole 
      // family (it's smallest than the parent and consequently all its children)
      // Repeat
      int i = size - 1;
      while((i-1)/2 >= 0 && heap[(i-1)/2]->freq > newNode->freq){
        heap[i] = heap[(i-1)/2];
        i = (i-1)/2;
      }

      // We have managed to create an unused spot for new node
      heap[i] = newNode;
    }


};









struct HuffmanCode{
  char data;
  int freq;
  string code;
  HuffmanCode(){}
  HuffmanCode(char d, int f, string c): data(d), freq(f), code(c){}
};
class HuffManCompression{

  int getLeafsNumber(TreeNode *root){
    if(root == nullptr) return 0;
    if(!root->left && !root->right) return 1;
    return getLeafsNumber(root->left) + getLeafsNumber(root->right);
  }

  void getHuffmanCodesUtil(HuffmanCode *hCodes, TreeNode *hroot, string currCode, int *pos){

    if(hroot == nullptr) return;
    if(!hroot->left && !hroot->right) {
      hCodes[*pos] = *new HuffmanCode(hroot->data, hroot->freq, currCode);
      (*pos)++; 
    }

    getHuffmanCodesUtil(hCodes, hroot->left, currCode == "0" ? "0" : currCode + "0", pos);
    getHuffmanCodesUtil(hCodes, hroot->right, currCode == "0" ? "1" : currCode + "1", pos);

  }


  public:
    TreeNode *root;

    TreeNode *buildHuffmanTree(char data[], int freq[], int arrSize){

      // Step 1: Create a leaf node for each unique character and 
      // build a min heap of all leaf nodes (Min Heap is used as a 
      // priority queue. The value of frequency field is used to 
      // compare two nodes in min heap. Initially, the least 
      // frequent character is at root)
      Heap hp = *new Heap(data, freq, arrSize);



      // Step 4: Repeat steps#2 and #3 until the heap contains only one node. 
      // The remaining node is the root node and the tree is complete.
      while(hp.getSize() != 1){

        // Step 2: Extract two nodes with the minimum frequency from the min heap.
        TreeNode *min1 = hp.extractMin();
        TreeNode *min2 = hp.extractMin();

        // Step 3: Create a new internal node with a frequency equal to the sum of 
        // the two nodes frequencies. Make the first extracted node as its left child 
        // and the other extracted node as its right child. Add this node to the min heap. 
        TreeNode *intNode = new TreeNode('$', min1->freq + min2->freq);
        intNode->left = min1;
        intNode->right = min2;
        hp.insert(intNode);

      }

      // The heap was dissolved and only has one element, 
      // now we only have the HuffMan tree with its root at heap[0]
      root = hp.extractMin();
      return root;
    }

    HuffmanCode * getHuffmanCodes(){
      int leafs = getLeafsNumber(root);
      HuffmanCode *hCodes = new HuffmanCode[leafs];
      int pos = 0;
      getHuffmanCodesUtil(hCodes, root, "0", &pos);
      return hCodes;
    }


};











// https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
int main(int argc, char **argv, char **envp){

  int arrSize = 6;
  char *data = new char[arrSize] {'a', 'b', 'c', 'd', 'e', 'f'};
  int *freq = new int[arrSize] {5, 9, 12, 13, 16, 45};

  HuffManCompression *hc = new HuffManCompression();

  hc->buildHuffmanTree(data, freq, arrSize);
  HuffmanCode *hcodes = hc->getHuffmanCodes();

  for(int i = 0 ; i < arrSize ; i++){
    cout << hcodes[i].data << "  " << hcodes[i].freq << "  " << hcodes[i].code << endl;
  }

  return 0;
}
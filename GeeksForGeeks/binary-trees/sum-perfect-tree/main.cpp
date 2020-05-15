#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node * left, * right;
};

Node* newNode(int data){
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}


int sumOfTree(int nLevels){
  if(nLevels == 0) return 0;

  int nLeaves = pow(2, nLevels - 1);

  return nLevels * nLeaves * (nLeaves + 1) / 2;
}




int main(){
    int nLevels = 3;
    int sum = sumOfTree(nLevels);
    assert(sum == 30);
    cout << "Sum of tree is = " << sum << endl; 
    return 0; 
}







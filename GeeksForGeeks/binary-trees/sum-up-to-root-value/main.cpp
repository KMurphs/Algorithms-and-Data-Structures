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


bool hasPairWithRootAsSum(Node* root, map<int, int> &treeData, int rootData){

  if(root == NULL) return false;

  if(treeData.find(root->data) != treeData.end()){
    return true;
  }
  treeData[rootData - root->data] = 1;


  if(
    hasPairWithRootAsSum(root->left, treeData, rootData) ||
    hasPairWithRootAsSum(root->right, treeData, rootData)
  )
    return true;
    
  return false;
}




int main(){

    Node *root = newNode(8); 
    root->left    = newNode(5); 
    root->right   = newNode(4); 
    root->left->left = newNode(9); 
    root->left->right = newNode(7); 
    root->left->right->left = newNode(1); 
    root->left->right->right = newNode(12); 
    root->left->right->right->right = newNode(2); 
    root->right->right = newNode(11); 
    root->right->right->left = newNode(3); 


    map<int, int> treeData;
    bool res = hasPairWithRootAsSum(root, treeData, root->data);

    
    assert(res == true);
    res ? cout << "Yes" : cout << "No"; 
    return 0; 
}







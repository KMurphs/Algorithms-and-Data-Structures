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


int getSumOfAllNodesWithChildValue(Node* root, int childVal){
  if(root == NULL) return 0;

  if((root->left && root->left->data == childVal) || 
     (root->right && root->right->data == childVal)
  )
    return root->data + 
      getSumOfAllNodesWithChildValue(root->left, childVal) +
      getSumOfAllNodesWithChildValue(root->right, childVal);

  return 0;
}




int main(){
    // binary tree formation 
    Node *root = newNode(4);           /*        4        */
    root->left = newNode(2);           /*       / \       */
    root->right = newNode(5);          /*      2   5      */
    root->left->left = newNode(7);     /*     / \ / \     */
    root->left->right = newNode(2);    /*    7  2 2  3    */
    root->right->left = newNode(2); 
    root->right->right = newNode(3); 
      
    int childValue = 2; 
    int sum = getSumOfAllNodesWithChildValue(root, childValue);
    assert(sum == 11);
    cout << "Sum = " << sum << endl; 
    return 0; 
}
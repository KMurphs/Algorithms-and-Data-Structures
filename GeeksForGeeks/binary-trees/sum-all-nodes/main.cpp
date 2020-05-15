#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* newNode(int data){
  Node* node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return node;
}


int sumAllNodes(Node* root){
  if(root == NULL) return 0;
  return root->data + sumAllNodes(root->left) + sumAllNodes(root->right);
}



int main(){
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 

    int sum = sumAllNodes(root); 
    cout << "Sum of all the elements is: " << sum << endl;
    assert(sum == 36);
    return 0;
}
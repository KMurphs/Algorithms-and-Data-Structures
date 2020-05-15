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


int sumAllLeftLeaves(Node* root){

  if(root == NULL) return 0;

  int res = 0;
  if(
    root->left && 
    root->left->left == NULL && 
    root->left->right == NULL
  )
    res = root->left->data;


  return res + sumAllLeftLeaves(root->left) + sumAllLeftLeaves(root->right);
}




int main(){
    Node *root         = newNode(20); 
    root->left                = newNode(9); 
    root->right               = newNode(49); 
    root->right->left         = newNode(23); 
    root->right->right        = newNode(52); 
    root->right->right->left  = newNode(50); 
    root->left->left          = newNode(5); 
    root->left->right         = newNode(12); 
    root->left->right->right  = newNode(12);
      

    int sum = sumAllLeftLeaves(root);
    assert(sum == 78);
    cout << "Sum of left leaves is = " << sum << endl; 
    return 0; 
}

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


int sumOfDiagonals(Node* root, map<int, int> &diagSums, int diagId){
  
  if(root == NULL) 
    return 0;

  diagSums[diagId] += root->data;
  sumOfDiagonals(root->left, diagSums, diagId + 1);
  sumOfDiagonals(root->right, diagSums, diagId);
  
  return 0;
}




int main(){
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(9); 
    root->left->right = newNode(6); 
    root->right->left = newNode(4); 
    root->right->right = newNode(5); 
    root->right->left->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->left->right->left = newNode(11); 
    root->left->left->right = newNode(10); 
  
    map<int, int> diagonalSums;  

    sumOfDiagonals(root, diagonalSums, 0); 

    int sols[] = {9, 19, 42}; 
    map<int, int>::iterator counter; 
    int i = 0;
    cout << "Diagonal sum in a binary tree is - "; 
    for(counter = diagonalSums.begin(); 
        counter != diagonalSums.end(); 
        ++counter
    ){
      
      cout << counter->second << " "; 
      assert(counter->second == sols[i++]);
    }

    return 0; 
}
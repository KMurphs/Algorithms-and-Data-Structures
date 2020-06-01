#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int val): value(val), left(nullptr), right(nullptr){}
  TreeNode(int val, TreeNode *l, TreeNode *r): value(val), left(l), right(r){}
};


int RemovePathsShorterThan(TreeNode *root, int K, int pathLength = 0){

  if(root == nullptr) return pathLength;

  int lLength = RemovePathsShorterThan(root->left, K, pathLength + 1);
  int rLength = RemovePathsShorterThan(root->right, K, pathLength + 1);


  if(lLength < K) root->left = nullptr;
  if(rLength < K) root->right = nullptr;
  if(lLength < K && rLength < K){
    free(root);
  }

  return max(lLength, rLength);
}



// https://www.geeksforgeeks.org/check-whether-binary-tree-full-binary-tree-not/
// A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
int main(int argc, char **argv, char **envp){

  TreeNode *root = new TreeNode(1);
  
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  root->left->left->left = new TreeNode(7);
  root->right->right->left = new TreeNode(8);
  vector<int> exp {5, 10, 3, 14, 25};

  RemovePathsShorterThan(root, 4);

  assert(root->value == 1);
  assert(root->left->left->left->value == 7);
  assert(root->left->right == nullptr);
  assert(root->right->right->left->value == 8);


  cout << "Program Exited Successfully...";
  return 0;
}
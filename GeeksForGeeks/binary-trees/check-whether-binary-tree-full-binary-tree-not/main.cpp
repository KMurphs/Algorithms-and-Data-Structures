#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int val): value(val), left(nullptr), right(nullptr){}
  TreeNode(int val, TreeNode *l, TreeNode *r): value(val), left(l), right(r){}
};


bool isFullBinaryTree(TreeNode *root){

  if(root == nullptr) return true;

  bool isValidNode = (
    (root->left != nullptr && root->right != nullptr) ||  
    (root->left == nullptr && root->right == nullptr)
  );

  return isValidNode && 
          isFullBinaryTree(root->left) &&
          isFullBinaryTree(root->right);
}




// https://www.geeksforgeeks.org/check-whether-binary-tree-full-binary-tree-not/
// A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
int main(int argc, char **argv, char **envp){

  TreeNode *root = new TreeNode(1);
  
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  bool isFull = isFullBinaryTree(root);
  cout << "Tree is " << (isFull ? "" : "NOT ") << "a full binary tree" << endl;
  assert(isFull == true);


  cout << "Program Exited Successfully...";
  return 0;
}
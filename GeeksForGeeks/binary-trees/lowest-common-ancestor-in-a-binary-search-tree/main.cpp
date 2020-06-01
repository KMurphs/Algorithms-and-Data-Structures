#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int val): value(val), left(nullptr), right(nullptr){}
  TreeNode(int val, TreeNode *l, TreeNode *r): value(val), left(l), right(r){}
};


int getLCA(TreeNode *root, int n1, int n2){

  if(root == nullptr) return INT_MIN;
  if(root->value == n1 || root->value == n2) return root->value;

  int lLCA = getLCA(root->left, n1, n2);
  int rLCA = getLCA(root->right, n1, n2);

  int lca = max(lLCA, rLCA);
  if(lLCA != INT_MIN && rLCA != INT_MIN)
    lca = root->value;
  
  return lca;
}



// https://www.geeksforgeeks.org/check-whether-binary-tree-full-binary-tree-not/
// A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
int main(int argc, char **argv, char **envp){

  TreeNode *root = new TreeNode(20);
  
  root->left = new TreeNode(8);
  root->right = new TreeNode(22);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(12);

  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(14);

  int n1 = 10, n2 = 22;
  int lca = getLCA(root, n1, n2);
  cout << "LCA of '" << n1 << "' and '" << n2 << "' is '" << lca << "'" << endl;

  assert(lca == 20);
  assert(getLCA(root, 10, 14) == 12);
  assert(getLCA(root, 8, 14) == 8);


  cout << "Program Exited Successfully...";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
// c++ struct and class are the same except ofr the fact that by
// default members in struct are public, in class private
struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int value): value(value), left(nullptr), right(nullptr){}
  TreeNode(int value, TreeNode *l, TreeNode *r): value(value), left(l), right(r) {}
};

int findMinDepth(TreeNode *root){
  if(root == nullptr) return 0;
  return 1 + min(findMinDepth(root->left), findMinDepth(root->right));
}


int main(int argc, char **argv, char **envp){

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  int minDepth = findMinDepth(root);
  cout << "Minimum Depth is: " << minDepth << endl;
  assert(minDepth == 2);

  cout << "\nProgram exited successfully\ns";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int val): value(val), left(nullptr), right(nullptr){}
  TreeNode(int val, TreeNode *l, TreeNode *r): value(val), left(l), right(r){}
};

bool areTreesIdentical(TreeNode *root1, TreeNode *root2){
  if(root1 == nullptr && root2 == nullptr) return true;
  // handle case bigger 1->2->3->4 shorter 2->3
  // if(root1 != nullptr && root2 == nullptr) return true; 
  // if(root1 == nullptr) return true;
  if(root1 == nullptr || root2 == nullptr) return false;

  return root1->value == root2->value && 
          areTreesIdentical(root1->left, root2->left) &&
          areTreesIdentical(root1->right, root2->right);
}


bool doesTreeContainsSubTree(TreeNode *mainRoot, TreeNode *secRoot){

  if(mainRoot == nullptr || secRoot == nullptr) return false;

  if(mainRoot->value == secRoot->value)
    if(areTreesIdentical(mainRoot, secRoot))
      return true;

  return doesTreeContainsSubTree(mainRoot->left, secRoot) || doesTreeContainsSubTree(mainRoot->right, secRoot);
}




// https://www.geeksforgeeks.org/check-binary-tree-subtree-another-binary-tree-set-2/
// Alternatively, since inorder and preorder/postorder traversal of a tree uniquely identifies it,
// We could compute for both trees, inorder and preorder traversal and check whether the traversals
// of the shorter tree is contained in the main tree. Use "nulls" to address situations where the bigger
// tree contains the shorter tree but goes beyond the ending point of the shorter tree
// bigger 1->2->3->4 shorter 2->3
int main(int argc, char **argv, char **envp){

  TreeNode *root1 = new TreeNode('x');
  root1->left = new TreeNode('a');
  root1->right = new TreeNode('b');
  root1->left->right = new TreeNode('c');

  TreeNode *root2 = new TreeNode('x');
  root1->left = new TreeNode('a');
  root1->right = new TreeNode('b');
  root1->left->right = new TreeNode('d');

  TreeNode *root = new TreeNode('z');
  root->left = root1;
  root->right = new TreeNode('e');
  root->right->right = new TreeNode('k');


  assert(doesTreeContainsSubTree(root, root1) == true);
  assert(doesTreeContainsSubTree(root, root2) == false);


  cout << "Program Exited Successfully...";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int val): value(val), left(nullptr), right(nullptr){}
  TreeNode(int val, TreeNode *l, TreeNode *r): value(val), left(l), right(r){}
};


int findMaxPathSumUtil(TreeNode *root, int *ptrGlobalMax){

  if(root == nullptr) return 0;

  int lMax = findMaxPathSumUtil(root->left, ptrGlobalMax);
  int rMax = findMaxPathSumUtil(root->right, ptrGlobalMax);

  int localMax = lMax + rMax + root->value;

  if(*ptrGlobalMax < localMax)
    *ptrGlobalMax = localMax;
  
  return root->value + max(lMax, rMax);
}

int findMaxPathSum(TreeNode *root){
  int maxSum = INT_MIN;
  findMaxPathSumUtil(root, &maxSum);
  return maxSum;
}


// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
int main(int argc, char **argv, char **envp){

  TreeNode *root = new TreeNode(10);
  
  root->left = new TreeNode(2);
  root->right = new TreeNode(10);

  root->left->left = new TreeNode(20);
  root->left->right = new TreeNode(1);
  root->right->right = new TreeNode(-25);

  root->right->right->left = new TreeNode(3);
  root->right->right->right = new TreeNode(4);

  int maxSum = findMaxPathSum(root);
  cout << "Maximum Path Sum is: " << maxSum << endl;
  assert(maxSum == 42);


  cout << "Program Exited Successfully...";
  return 0;
}
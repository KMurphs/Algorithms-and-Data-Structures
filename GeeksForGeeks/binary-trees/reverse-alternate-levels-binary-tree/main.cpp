#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int val): value(val), left(nullptr), right(nullptr){}
  TreeNode(int val, TreeNode *l, TreeNode *r): value(val), left(l), right(r){}
};


void reverseAlternateTreeLevels(TreeNode *root){

  bool mustReverse = false;
  vector<TreeNode *>currQ, nextQ, tmpQ;
  TreeNode *curr;
  currQ.push_back(root);

  while(currQ.size() != 0 || nextQ.size() != 0){
    curr = currQ.front();
    currQ.erase(currQ.begin());
    
    if(curr->left) nextQ.push_back(curr->left);
    if(curr->right) nextQ.push_back(curr->right);

    // Preparing for next Level
    if(currQ.size() == 0){

      // Reverse values for the node in the Q
      mustReverse = !mustReverse;
      if(mustReverse){
        int l = 0, r = nextQ.size() - 1, tmpVal;
        while(l < r){
          tmpVal = nextQ[l]->value;
          nextQ[l]->value = nextQ[r]->value;
          nextQ[r]->value = tmpVal;
          l++;
          r--;
        }
      }

      // Swapping pointers so that currQ
      // is always the Q to be processed now
      tmpQ = currQ;
      currQ = nextQ;
      nextQ = tmpQ;
    }
  }


}



// https://www.geeksforgeeks.org/check-whether-binary-tree-full-binary-tree-not/
// A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
int main(int argc, char **argv, char **envp){

  TreeNode *root = new TreeNode('a');
  
  root->left = new TreeNode('b');
  root->right = new TreeNode('c');

  root->left->left = new TreeNode('d');
  root->left->right = new TreeNode('e');
  root->right->left = new TreeNode('f');
  root->right->right = new TreeNode('g');

  root->left->left->left = new TreeNode('h');
  root->left->left->right = new TreeNode('i');
  root->left->right->left = new TreeNode('j');
  root->left->right->right = new TreeNode('k');
  root->right->left->left = new TreeNode('l');
  root->right->left->right = new TreeNode('m');
  root->right->right->left = new TreeNode('n');
  root->right->right->right = new TreeNode('o');


  reverseAlternateTreeLevels(root);
  assert(root->value == 'a');
  assert(root->left->value == 'c');
  assert(root->left->left->value == 'd');
  assert(root->left->left->left->value == 'o');
  assert(root->right->value == 'b');
  assert(root->right->right->value == 'g');
  assert(root->right->right->right->value == 'h');

  cout << "Program Exited Successfully...";
  return 0;
}
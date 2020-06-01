#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int val): value(val), left(nullptr), right(nullptr){}
  TreeNode(int val, TreeNode *l, TreeNode *r): value(val), left(l), right(r){}
};


vector<int> getBottomView(TreeNode *root){

  map<int, int> view;
  vector<pair<TreeNode *, int>>Q;
  Q.push_back(pair<TreeNode *, int>(root, 0));


  pair<TreeNode *, int> curr;
  while(Q.size() != 0){
    curr = Q.front();
    Q.erase(Q.begin());


    view[curr.second] = curr.first->value;
    if(curr.first->left)  Q.push_back(pair<TreeNode *, int>(curr.first->left, curr.second - 1));
    if(curr.first->right) Q.push_back(pair<TreeNode *, int>(curr.first->right, curr.second + 1));
  }


  vector<int> bottomView;
  map<int, int>::iterator itr; 
  for (itr = view.begin(); itr != view.end(); ++itr) { 
    cout << itr->second << " ";
    bottomView.push_back(itr->second);
  } 
  cout << endl;

  return bottomView;
}



// https://www.geeksforgeeks.org/check-whether-binary-tree-full-binary-tree-not/
// A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
int main(int argc, char **argv, char **envp){

  TreeNode *root = new TreeNode(20);
  
  root->left = new TreeNode(8);
  root->right = new TreeNode(22);

  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(25);

  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(14);
  vector<int> exp {5, 10, 3, 14, 25};

  vector<int> bottomView = getBottomView(root);
  for(int i = 0; i < bottomView.size(); i++){
    cout << bottomView[i] << " ";
    assert(bottomView[i] == exp[i]);
  }
  cout << endl;
  assert(bottomView.size() == 4);


  cout << "Program Exited Successfully...";
  return 0;
}
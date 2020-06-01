#include <bits/stdc++.h>

using namespace std;


struct TreeNode{
  int value;
  TreeNode *left, *right;
  TreeNode(int val): value(val), left(nullptr), right(nullptr){}
  TreeNode(int val, TreeNode *l, TreeNode *r): value(val), left(l), right(r){}
};


vector<int> getTopView(TreeNode *root){

  map<int, int> view;
  vector<pair<TreeNode *, int>>Q;
  Q.push_back(pair<TreeNode *, int>(root, 0));


  pair<TreeNode *, int> curr;
  while(Q.size() != 0){
    curr = Q.front();
    Q.erase(Q.begin());

    if(view.find(curr.second) == view.end())
      view[curr.second] = curr.first->value;
    if(curr.first->left)  Q.push_back(pair<TreeNode *, int>(curr.first->left, curr.second - 1));
    if(curr.first->right) Q.push_back(pair<TreeNode *, int>(curr.first->right, curr.second + 1));
  }


  vector<int> topView;
  map<int, int>::iterator itr; 
  for (itr = view.begin(); itr != view.end(); ++itr) { 
    cout << itr->second << " ";
    topView.push_back(itr->second);
  } 
  cout << endl;

  return topView;
}



// https://www.geeksforgeeks.org/check-whether-binary-tree-full-binary-tree-not/
// A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
int main(int argc, char **argv, char **envp){

  TreeNode *root = new TreeNode(1);
  
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->right = new TreeNode(4);
  root->left->right->right = new TreeNode(5);
  root->left->right->right->right = new TreeNode(5);


  vector<int> exp {2, 1, 3, 5, 6};

  vector<int> topView = getTopView(root);
  for(int i = 0; i < topView.size(); i++){
    cout << topView[i] << " ";
    assert(topView[i] == exp[i]);
  }
  cout << endl;
  assert(topView.size() == 4);


  cout << "Program Exited Successfully...";
  return 0;
}
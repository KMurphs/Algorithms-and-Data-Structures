/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> res;

        TreeNode* curr = root;
        while(curr != NULL){
          stack.push_back(curr);
          curr = curr->left;
        }



        while(true){
          if(stack.size() == 0) break;

          curr = stack.back();
          stack.pop_back();
          res.push_back(curr->val);

          curr = curr->right;
          while(curr != NULL){
            stack.push_back(curr);
            curr = curr->left;
          }

        }


        return res;
    }
};


int main() {
    TreeNode* root = new TreeNode(10);
    vector<int> res = Solution().inorderTraversal(root);
    vector<int> vals = { 10 };
    

    vector<int>::iterator counter;
    vector<int>::iterator val;
    cout << "In Order Traversal: ";
    for(counter = res.begin(), val = vals.begin(); counter != res.end(); ++counter){
      cout << *counter;
      assert(*val == *counter);
    }
      
    cout << endl;


    return 0;
}
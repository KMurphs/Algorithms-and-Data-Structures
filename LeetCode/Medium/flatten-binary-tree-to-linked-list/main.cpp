
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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* pre = root;
        while(curr != nullptr){
            if(curr->left){
                
                pre = curr->left;
                while(pre->right != nullptr) pre = pre->right;
                
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            
            curr = curr->right;
        }
    }
};
        

int main() {
    TreeNode* root = new TreeNode(10);
    Solution().flatten(root);

    // bool isMatch = exp.size() == res.size();
    // cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root, int acc = 0) {
        
        if(root == nullptr){
            return 0;
        }
        
        int newAcc = (acc * 10) + root->val;
        int newSum = 0;
        
        if(root->left == nullptr && root->right == nullptr){
            newSum += newAcc;
        }else{
            newSum += sumNumbers(root->left, newAcc);
            newSum += sumNumbers(root->right, newAcc);
        }
        
        return newSum;
        
    }
};
        

int main() {
    TreeNode* root = new TreeNode(9);
    assert(Solution().sumNumbers(root) == 9);

    // cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}
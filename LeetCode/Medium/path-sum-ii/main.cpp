
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> solutions;
        if(root == NULL){ return solutions; }
        
        vector<int> currentChoices;
        backTracking(solutions, currentChoices, 0, sum, root);
        return solutions;
    }
    void backTracking(vector<vector<int>>& sols, vector<int>& curr, int currSum, int targetSum, TreeNode* root){
        
        if(root == NULL){ 
            return; 
        }
        
        // Commiting the current choice
        curr.push_back(root->val);
        currSum = currSum + root->val;
        
        if( //We have a leaf, and all our choices match the target sum
            root->left == nullptr && 
            root->right == nullptr && 
            currSum == targetSum
        ){
            vector<int> tmp(curr); 
            sols.push_back(tmp);
        }
        
        if(root->left != nullptr) backTracking(sols, curr, currSum, targetSum, root->left);
        if(root->right != nullptr) backTracking(sols, curr, currSum, targetSum, root->right);
        
        // Undoing the choice
        currSum = currSum - root->val;
        curr.pop_back();
        
    }
};
        

int main() {
    TreeNode* root = new TreeNode(10);
    Solution().pathSum(root, 10);

    // bool isMatch = exp.size() == res.size();
    // cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}
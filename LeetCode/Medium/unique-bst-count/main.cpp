
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
    bool isValidBST(TreeNode* root) {
        int rMax = 0, rMin = 0;
        // return isValidBSTAndReportExtremums(root, &rMax, &rMin);
        return check(root, INT_MIN, INT_MAX);
    }

    // Consider difference between both approach
    // This one injects the limit, the later one collects the limits and as to deal with pointer
    // And it seems that pointer referencing/derefencing at each recusrsive call
    // puts a burden on the overall speed
    bool check(TreeNode* rt, long int l, long int r){
        if(!rt) return true;
        if(rt->val <= l || rt->val >= r) return false;

        return check(rt->left, l, rt->val) & check(rt->right, rt->val, r);
        
    }
    
    bool isValidBSTAndReportExtremums(TreeNode* root, int* rMax, int* rMin){
        
        *rMax = INT_MIN;
        *rMin = INT_MAX;
        if(root == NULL){
            return true;
        }
        
        int lM, rM, lm, rm;
        if(
            isValidBSTAndReportExtremums(root->left, &lM, &lm) &&
            isValidBSTAndReportExtremums(root->right, &rM, &rm)
        ){
            if(
                (lM < root->val && root->val < rm) ||
                (root->val == INT_MIN && root->left == NULL && root->val < rm) ||
                (root->val == INT_MAX && root->right == NULL && lM < root->val)
            ){
                *rMax = max(root->val, max(lM, rM));
                *rMin = min(root->val, min(lm, rm));
                return true;
            }

        }
        
        
        return false;
    }
};


int main() {
    TreeNode* root = new TreeNode(10);
    bool res = Solution().isValidBST(root);
    bool exp = true;
    
    assert(res == exp);
    cout << "Tree is " << (res==exp ? "" : " not ") << " A Valid BST" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}
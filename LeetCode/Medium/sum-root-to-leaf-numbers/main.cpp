
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
    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;
        dfs(root, &num, &sum);
        return sum;
    }
    void dfs(TreeNode* root, int* ptrNum, int* ptrSum){
        
        if(root == nullptr){
            return;
        }
        
        int tmp = *ptrNum;
        *ptrNum = (tmp * 10) + root->val;
        
        
        if(root->left == nullptr && root->right == nullptr){
            *ptrSum = *ptrSum + *ptrNum;
        }else{
            dfs(root->left, ptrNum, ptrSum);
            dfs(root->right, ptrNum, ptrSum);
        }
        
        *ptrNum = tmp;
    }
    
};
        

int main() {
    TreeNode* root = new TreeNode(9);
    assert(Solution().sumNumbers(root) == 9);

    // cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}
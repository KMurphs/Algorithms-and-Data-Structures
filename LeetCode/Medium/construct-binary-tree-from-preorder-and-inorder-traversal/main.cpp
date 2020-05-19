
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
    TreeNode* buildTree(vector<int>& poArr, vector<int>& ioArr) {
        int poIdx = 0;
        int ioIdx = 0;
        return buildTreeRecur(poArr, ioArr, &poIdx, &ioIdx, INT_MAX);
    }

    TreeNode* buildTreeRecur(vector<int>& poArr, vector<int>& ioArr, int* poIdx, int* ioIdx, int rootVal) {
        
        if(*ioIdx >= ioArr.size() || ioArr[*ioIdx] == rootVal) return NULL;
        
        TreeNode* curr = new TreeNode(poArr[(*poIdx)++]);
        curr->left  = buildTreeRecur(poArr, ioArr, poIdx, ioIdx, curr->val);
        (*ioIdx)++;
        curr->right = buildTreeRecur(poArr, ioArr, poIdx, ioIdx, rootVal);
        return curr;
    }
};
        

int main() {
    vector<int> io = {4, 2, 5, 1, 6, 3};
    vector<int> po = {1, 2, 4, 5, 3, 6};
    TreeNode* res = Solution().buildTree(po, io);
    TreeNode* exp;



    // bool isMatch = exp.size() == res.size();
    // cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;


    return 0;
}
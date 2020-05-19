
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> sols;
        if(n == 0) return sols;
        return buildTrees(1, n);
    }
    
    vector<TreeNode*> buildTrees(int l, int r){
        vector<TreeNode*> sols;
        if(l > r){
            sols.push_back(NULL);
            return sols;
        }
        
        
        for(int i = l; i <= r; i++){
            vector<TreeNode*> lTrees = buildTrees(l, i - 1);
            vector<TreeNode*> rTrees = buildTrees(i + 1, r);
            
            for(int lt = 0; lt < lTrees.size(); lt++){
                for(int rt = 0; rt < rTrees.size(); rt++){
                    TreeNode* root = new TreeNode(i);
                    root->left = lTrees[lt];
                    root->right = rTrees[rt];
                    sols.push_back(root); 
                }
            }
        }
        
        return sols;
    }
};
        

int main() {
    int n = 1;
    vector<TreeNode*> res = Solution().generateTrees(n);
    vector<TreeNode*> exp;
    exp.push_back(new TreeNode(1));


    bool isMatch = exp.size() == res.size();
    cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;


    return 0;
}
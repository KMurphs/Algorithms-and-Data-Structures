
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        pair<int, TreeNode*> curr;
        queue<pair<int, TreeNode*>> Q;
        int level;
        TreeNode* currNode;
        if(root != NULL) Q.push(pair<int, TreeNode*>(0, root));
        
        
        while(Q.size() != 0){
            curr = Q.front();
            Q.pop();
            
            level = curr.first;
            currNode = curr.second;
            
            if(level == res.size()){ vector<int> h; res.push_back(h); }
            res[level].push_back(currNode->val);
            
            if(currNode->left != NULL)  Q.push(pair<int, TreeNode*>(level + 1, currNode->left));
            if(currNode->right != NULL) Q.push(pair<int, TreeNode*>(level + 1, currNode->right));
        }
        
        return res;
    }
};


int main() {
    TreeNode* root = new TreeNode(10);
    vector<vector<int>> res = Solution().levelOrder(root);
    vector<vector<int>> exp;
    exp.push_back({ 10 });

    vector<vector<int>>::iterator resIt, expIt;
    vector<int>::iterator resit, expit;
    bool isMatch = true;
    for(
        resIt = res.begin(), expIt = exp.begin(); 
        resIt != res.end() && expIt != exp.end(); 
        ++resIt, ++expIt
    ){
       for(
           resit = (*resIt).begin(), expit = (*expIt).begin(); 
           resit != (*resIt).end() && expit != (*expIt).end(); 
           ++resit, ++expit
        ){
            assert(*resit == *expit);
            isMatch = isMatch && (*resit == *expit);  
        } 
        cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;
    }


    return 0;
}
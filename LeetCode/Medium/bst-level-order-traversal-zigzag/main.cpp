
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        vector<int> tmp;

        deque<TreeNode*> currQ, nextQ, tmpQ;
        TreeNode* curr;
        bool evenLevel = false;
        
        if(root != NULL) currQ.push_back(root);
        
        while(currQ.size() != 0 || nextQ.size() != 0){
            
            while(currQ.size() != 0){
                curr = currQ.front();
                currQ.pop_front();
                    
                tmp.push_back(curr->val);
                if(curr->left != NULL)  nextQ.push_back(curr->left);
                if(curr->right != NULL) nextQ.push_back(curr->right);
            }
    
            tmpQ = currQ;
            currQ = nextQ;
            nextQ = tmpQ;
            
            if(evenLevel) reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            tmp.clear();
            
            evenLevel = !evenLevel;
        }
        
        return res;
    }
};


int main() {
    TreeNode* root = new TreeNode(10);
    vector<vector<int>> res = Solution().zigzagLevelOrder(root);
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
        cout << "ZigZag Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;
    }


    return 0;
}
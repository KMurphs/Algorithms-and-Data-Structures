
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
    int numTrees(int n) {
        vector<int> dp = { 1 };
        
        for(int i = 1; i <= n; i++){
            dp.push_back(0);
            for(int j = 0; j <= i - 1; j++){
                dp[i] = dp[i] + dp[j]*dp[i - j - 1];
            }
        }
        
        return dp[n];
    }
};


int main() {
    int n = 4;
    int res = Solution().numTrees(n);
    int exp = 14;
    
    assert(res == exp);
    cout << "For n = '" << n << "': There are '" << res << "' possible structurally unique BSTs" << endl;


    return 0;
}
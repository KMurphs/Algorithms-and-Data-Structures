
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

class Solution {
public:
    int minimumTotal1(vector<vector<int>>& triangle){
        int rows = triangle.size();
        int cols = triangle[rows - 1].size();
        int minVal = triangle[0][0];

        for(int i = 1; i < rows; i++){
            minVal = INT_MAX;
            for(int j = 0; j <= i; j++){
                triangle[i][j] += min(
                    j - 1 < 0 ? INT_MAX : triangle[i - 1][j - 1],
                    j >= triangle[i - 1].size() ? INT_MAX : triangle[i - 1][j]
                );
                minVal = minVal < triangle[i][j] ? minVal : triangle[i][j];
            }
        }
        
        return minVal;
    }
    int minimumTotal2(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
        vector<int> choices {0};
        backTracking(triangle, choices, triangle[0][0], &minSum);
        
        return minSum;
    }
    void backTracking(vector<vector<int>>& triangle, vector<int>& currChoices, int currSum, int* minSum){
        
        
        int prevLevel = currChoices.size();
        int prevPos = currChoices[prevLevel - 1];
        
        if(prevLevel == triangle.size()) {
            if(currSum < *minSum) *minSum = currSum;
            return;
        }
        
        for(int i = 0; i < 2; i++){
            if(prevPos + i >= triangle[prevLevel].size()) continue;
            
            currChoices.push_back(prevPos + i);
            backTracking(triangle, currChoices, currSum + triangle[prevLevel][prevPos + i], minSum);
            currChoices.pop_back();
        }

        
    }
};
        

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}}; 
    int exp = 11;
    assert(Solution().minimumTotal2(triangle) == exp);
    assert(Solution().minimumTotal1(triangle) == exp);

    // cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}
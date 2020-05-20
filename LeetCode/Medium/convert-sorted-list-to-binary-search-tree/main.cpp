
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        int counter = 0;
        ListNode* curr = head;
        while(curr != NULL){
            curr = curr->next;
            counter++;
        }
        
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;
        return convertToBST(dummyHead, counter);
    }
    
    TreeNode* convertToBST(ListNode* start, int length){
        
        if(length <= 0){ return NULL; }
        if(start == nullptr) { return NULL; }
        
        ListNode* curr = start;
        int counter = 0;
        while(counter < length/2){
            curr = curr->next;
            counter++;
        }
        
        TreeNode* root = new TreeNode(curr->next->val);
        root->left  = convertToBST(start, counter);
        root->right = convertToBST(curr->next, length - counter - 1);
        
        return root;
    }
};
        

int main() {
    ListNode* root = new ListNode(10);
    Solution().sortedListToBST(root);

    // bool isMatch = exp.size() == res.size();
    // cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}
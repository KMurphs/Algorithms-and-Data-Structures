
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
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* connect1(Node* root) {
    
        if(root == nullptr) return root;
        
        Node* l = root->left;
        Node* r = root->right;
        int level = 1;
        while(l != nullptr && r != nullptr){
            l->next = r;
            l = findDescendant(root->left ,  level, true);
            r = findDescendant(root->right,  level, false);
            level++;
        }
        
        connect1(root->left);
        connect1(root->right);
        return root;
    
    }
    Node* findDescendant(Node* root, int level, bool onLeftSide){
        if(root == nullptr) return root;
        if(level <= 0) return root;
        
        Node* prim = onLeftSide ? root->right : root->left; 
        Node* sec  = onLeftSide ? root->left : root->right; 
        
        Node* res = findDescendant(prim, level - 1, onLeftSide);
        if(res == nullptr){
            res = findDescendant(sec, level - 1, onLeftSide);
        }
        
        return res;
    }

    Node* connect2(Node* root) {
        
        if(root == nullptr) return root;
        
        Node* dummy = new Node(0);
        Node* runningParent = root;
        Node* runningSibling = dummy;
        
        bool isCompleted = false;
    
        while(!isCompleted){
            
            if(runningParent->left){
                runningSibling->next = runningParent->left;
                runningSibling = runningSibling->next;
            }
            if(runningParent->right){
                runningSibling->next = runningParent->right;
                runningSibling = runningSibling->next;
            }
            
            if(runningParent->next == nullptr){
                
                isCompleted = runningSibling == dummy;
                runningParent = dummy->next;
                runningSibling = dummy;
                
            }else{
                runningParent = runningParent->next;
            }
            
        }
        
        return root;
    }

};
        

int main() {
    Node* root = new Node(10);
    assert(Solution().connect1(root) == root);
    assert(Solution().connect2(root) == root);

    // cout << "Results " << (isMatch ? "" : "do not ") << "match expected data" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}

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


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == nullptr){ return root; }
        
        Node* l = root->left;
        Node* r = root->right;
        if(l != nullptr && r != nullptr) {
            l->next = r;
            
            Node* ltmp = l->right;
            Node* rtmp = r->left;
            while(ltmp != nullptr && rtmp != nullptr) {
                ltmp->next = rtmp;
                ltmp = ltmp->right;
                rtmp = rtmp->left;
            }
            
        }
        
        connect(root->left);
        connect(root->right);
        return root;
    
    }
};


int main() {
    Node* root = new Node(10);
    Node* res = Solution().connect(root);
    Node* exp = root;
    
    assert(res == exp);
    cout << "Tree is " << (res==exp ? "" : " not ") << " Correct" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}
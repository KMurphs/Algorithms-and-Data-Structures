// C program for flattening a linked list 
#include <stdio.h> 
#include <stdlib.h> 

#include <bits/stdc++.h>
using namespace std;

// A Linked List Node 
typedef struct Node 
{ 
    int data; 
    struct Node *right; 
    struct Node *down; 
} Node; 
  
/* A utility function to insert a new node at the begining 
   of linked list */
void push (Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = (Node *) malloc(sizeof(Node)); 
    new_node->right = NULL; 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->down = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
/* Function to print nodes in the flattened linked list */
void printList(Node *node, bool downDirection = true) 
{ 
    printf("\n");
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = downDirection ? node->down : node->right; 
    } 
} 
  
// A utility function to merge two sorted linked lists 
Node* merge( Node* a, Node* b ) 
{ 
    // If first list is empty, the second list is result 
    if (a == NULL) 
        return b; 
  
    // If second list is empty, the second list is result 
    if (b == NULL) 
        return a; 
  
    // Compare the data members of head nodes of both lists 
    // and put the smaller one in result 
    Node* result; 
    if (a->data < b->data) 
    { 
        result = a; 
        result->down = merge( a->down, b ); 
    } 
    else
    { 
        result = b; 
        result->down = merge( a, b->down ); 
    } 
  
    result->right = NULL; 
    return result; 
} 
  
// The main function that flattens a given linked list 
Node* flatten (Node* root) 
{ 
    // Base cases 
    if (root == NULL || root->right == NULL) 
        return root; 
  
    // Merge this list with the list on right side 
    return merge( root, flatten(root->right) ); 
} 
  

Node* flatten2 (Node* root) 
{ 
    if(root == nullptr) return root;
    Node* runner = root;
    Node *lc, *lh, *lv;

    while(runner != nullptr){

        while(runner != nullptr && runner->down == nullptr) runner = runner->right;
        if(runner == nullptr) break;

        lc = runner;
        lh = runner->right;
        lv = runner->down;
        lc->right = nullptr;
        lc->down = nullptr;
        
        while(lh != nullptr && lv != nullptr){
            if(lh->data < lv->data){
                lc->right = lh;
                lc = lc->right;
                lh = lh->right;
            } else {
                lc->right = lv;
                lc = lc->right;
                lv = lv->down;
                lc->down = nullptr;
            }
        }

        while(lh != nullptr){
            lc->right = lh;
            lc = lc->right;
            lh = lh->right;
        }
        while(lv != nullptr){
            lc->right = lv;
            lc = lc->right;
            lv = lv->down;
            lc->down = nullptr;
        }
        
    }
    return root;
}



// Driver program to test above functions 
int main() 
{ 
    Node* root = NULL; 
  
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    push( &root, 30 ); 
    push( &root, 8 ); 
    push( &root, 7 ); 
    push( &root, 5 ); 
  
    push( &( root->right ), 20 ); 
    push( &( root->right ), 10 ); 
  
    push( &( root->right->right ), 50 ); 
    push( &( root->right->right ), 22 ); 
    push( &( root->right->right ), 19 ); 
  
    push( &( root->right->right->right ), 45 ); 
    push( &( root->right->right->right ), 40 ); 
    push( &( root->right->right->right ), 35 ); 
    push( &( root->right->right->right ), 20 ); 
  
    // Let us flatten the list 
    root = flatten(root); 

    // Let us print the flatened linked list 
    printList(root); 


    Node* root2 = NULL; 
  
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    push( &root2, 30 ); 
    push( &root2, 8 ); 
    push( &root2, 7 ); 
    push( &root2, 5 ); 
  
    push( &( root2->right ), 20 ); 
    push( &( root2->right ), 10 ); 
  
    push( &( root2->right->right ), 50 ); 
    push( &( root2->right->right ), 22 ); 
    push( &( root2->right->right ), 19 ); 
  
    push( &( root2->right->right->right ), 45 ); 
    push( &( root2->right->right->right ), 40 ); 
    push( &( root2->right->right->right ), 35 ); 
    push( &( root2->right->right->right ), 20 ); 

    // Let us flatten the list 
    root2 = flatten2(root2); 

    // Let us print the flatened linked list 
    printList(root2, false); 

    return 0; 
} 
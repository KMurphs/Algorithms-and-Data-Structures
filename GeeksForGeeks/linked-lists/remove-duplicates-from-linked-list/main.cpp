
// C program for flattening a linked list 
#include <stdio.h> 
#include <stdlib.h> 

#include <bits/stdc++.h>
using namespace std;

// A Linked List Node 
typedef struct Node 
{ 
    int data; 
    struct Node *next; 
    Node(int d) : data(d){};
    Node(int d, Node *next) : data(d), next(next){};
} Node; 

void printList(Node *node) 
{ 
    printf("\n");
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}   

Node *removeDuplicates(Node *root)
{
 // your code goes here
    if(root == nullptr) return nullptr;
    
    Node *cacher = root, *prober = root->next;
    while(prober != nullptr){
        while(prober != nullptr && prober->data == cacher->data){
            prober = prober->next;
        }
        cacher->next = prober;
        cacher = cacher->next;
        if(prober != nullptr) prober = prober->next;
    }
    return root;
}


// Driver program to test above functions 
int main() 
{ 
    vector<int> data {6, -6, 8, 4, 4, -12, 9, -8};
    Node *root = new Node(data[0]), *curr; 
    curr = root;
    
    for(int i = 1; i < data.size(); i++){
        curr->next = new Node(data[i]);
        curr = curr->next;
    }
    curr->next = nullptr;

    // Let us flatten the list 
    root = removeDuplicates(root); 

    // Let us print the flatened linked list 
    printList(root);  

    return 0; 
} 

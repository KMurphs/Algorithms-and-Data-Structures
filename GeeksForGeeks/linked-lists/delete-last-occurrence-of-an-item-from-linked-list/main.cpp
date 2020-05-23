
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

Node *deleteLast(Node *root, int elmt)
{
    if(root == nullptr) return nullptr;

    Node *dummy = new Node(0, root);    
    Node *pre = dummy, *runner = dummy;  

    while(runner != nullptr){
        if(runner->next && runner->next->data == elmt){
            pre = runner;
        }
        runner = runner->next;
    }
    if(pre) pre->next = pre->next->next;

    return dummy->next;
}


// Driver program to test above functions 
int main() 
{ 
    vector<int> data {9};
    Node *root = new Node(data[0]), *curr; 
    curr = root;
    
    for(int i = 1; i < data.size(); i++){
        curr->next = new Node(data[i]);
        curr = curr->next;
    }
    curr->next = nullptr;

    // Let us flatten the list 
    root = deleteLast(root, 9); 

    // Let us print the flatened linked list 
    printList(root);  

    return 0; 
} 

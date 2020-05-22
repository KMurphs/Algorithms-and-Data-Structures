
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

Node *addOne(Node *head)
{
    if(head == nullptr) return head;
    
    Node *dummy = new Node(0, head);

    // Your Code here
    Node *msbc = dummy, *lsb = dummy;
    while(lsb->next != nullptr){
        lsb = lsb->next;
        if(lsb->data != 9) msbc = lsb;
    }
    while(msbc != nullptr){
        msbc->data = (msbc->data + 1)%10;
        msbc = msbc->next;
    }
    return dummy->data == 0 ? head : dummy;
}


// Driver program to test above functions 
int main() 
{ 
    vector<int> data {1,9,9,9};
    Node *root = new Node(data[0]), *curr; 
    curr = root;
    
    for(int i = 1; i < data.size(); i++){
        curr->next = new Node(data[i]);
        curr = curr->next;
    }
    curr->next = nullptr;

    // Let us flatten the list 
    root = addOne(root); 

    // Let us print the flatened linked list 
    printList(root); 

    return 0; 
} 

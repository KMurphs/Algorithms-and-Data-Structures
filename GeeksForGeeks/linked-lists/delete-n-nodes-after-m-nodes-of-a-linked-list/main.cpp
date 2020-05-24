
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

Node* deleteMaFterN(Node* head, int M, int N) {

    // Handle null case
    if(head == nullptr) return head;
    if(M <= 0) return head;
    
    // Handle all other cases
    Node *dummy = new Node(0);
    dummy->next = head;
    
    Node *ahead = dummy, *behind = dummy;
    int counter = N;
    while(ahead != nullptr && counter > 0){
        ahead = ahead->next;
        counter--;
    }
    if(ahead == nullptr) return head;

    behind = ahead;

    counter = M;
    while(ahead != nullptr && counter >= 0){
        ahead = ahead->next;
        counter--;
    }
    behind->next = ahead;

    return dummy->next;
}


// Driver program to test above functions 
int main() 
{ 
    vector<int> data {6, -6, 8, 4, -12, 9, -8};
    Node *root = new Node(data[0]), *curr; 
    curr = root;
    
    for(int i = 1; i < data.size(); i++){
        curr->next = new Node(data[i]);
        curr = curr->next;
    }
    curr->next = nullptr;

    // Let us flatten the list 
    root = deleteMaFterN(root, -1, -1); 

    // Let us print the flatened linked list 
    printList(root); 

    return 0; 
} 

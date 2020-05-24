
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
Node *buildLinkedList(vector<int> data){
    Node *root = new Node(data[0]), *curr; 
    curr = root;
    
    for(int i = 1; i < data.size(); i++){
        curr->next = new Node(data[i]);
        curr = curr->next;
    }
    curr->next = nullptr;
    return root;
}



Node* mergeWithAlternation(Node* head1, Node* head2) {

    // Handle all other cases
    Node *dummy = new Node(0);
    Node *newHead = dummy;
    bool choosingFirst = true;
    while(head1 != nullptr && head2 != nullptr){
        if(choosingFirst){
            newHead->next = head1;
            head1 = head1->next;
        }else{
            newHead->next = head2;
            head2 = head2->next;
        }
        newHead = newHead->next;
        choosingFirst = !choosingFirst;
    }
    while(head1 != nullptr){
        newHead->next = head1;
        newHead = newHead->next;
        head1 = head1->next;
    }
    while(head2 != nullptr){
        newHead->next = head2;
        newHead = newHead->next;
        head2 = head2->next;
    }

    return dummy->next;
}



// Driver program to test above functions 
int main() 
{ 

    // Let us flatten the list 
    Node *root = mergeWithAlternation(
        buildLinkedList({1,2,3,4,5,6,7,8,9}), 
        buildLinkedList({9,8,7,6,5})
    ); 

    // Let us print the flatened linked list 
    printList(root); 

    return 0; 
} 


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



Node* reverse(Node* head) {

    if(head == nullptr) return head;

    Node *backward = head;
    Node *forward = head->next;
    Node *tmp;

    backward->next = nullptr;

    while(forward != nullptr){
        tmp = forward->next;
        forward->next = backward;
        backward = forward;
        forward = tmp;
    }

    return backward;
}
Node* reverseRecursive(Node *forward, Node **backward = nullptr) {

    if(backward == nullptr){
        Node* tmp = nullptr;
        backward = &tmp;
    }
    if(forward == nullptr) {
        return nullptr;
    }

    Node *tmp = forward->next;
    forward->next = (*backward);
    (*backward) = forward;

    reverseRecursive(tmp, backward);

    return *backward;
}



// Driver program to test above functions 
int main() 
{ 

    // Let us flatten the list 
    Node *root = reverse(
        buildLinkedList({1,2,3,4,5,6,7,8,9})
    ); 
    printList(root); 


    root = reverseRecursive(root); 
    printList(root); 


    return 0; 
} 


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

Node* cancelOut(Node *head, int sumTarget)
{
    Node *dummy = new Node(0, head);
    Node *start = dummy;
    Node *end;
    int currSum;
    bool didCancelSome;

    while(start != nullptr){
    
        currSum = start->data;
        end = start->next;

        didCancelSome = false;

        while(end != nullptr){
            currSum += end->data;
            if(currSum == sumTarget){
                start->next = end->next;
                didCancelSome = true;
                break;
            }
            end = end->next;
        }

        if(!didCancelSome) start = start->next;
    }

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
    root = cancelOut(root, 0); 

    // Let us print the flatened linked list 
    printList(root); 

    return 0; 
} 

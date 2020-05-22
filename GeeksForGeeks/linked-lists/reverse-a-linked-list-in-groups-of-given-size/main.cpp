
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

// struct node
// {
//     int data;
//     struct node* next;
    
//     node(int x){
//         data = x;
//         next = NULL;
//     }
    
// } *head;


void printList(Node *node) 
{ 
    printf("\n");
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}   

Node *reverse(Node *head, int k)
{
    if(head == nullptr) return head;
    if(k <= 1) return head;
    
    Node *dummy = new Node(0, head);

    
    
    Node *currAnchor, *nextAnchor;
    Node *revHead, *revAnchor, *revRunner, *tmp;
    int counter;
    
    currAnchor = dummy;       // Sits at just before the current group to be reversed
    nextAnchor = dummy->next; // Sits at the beginning of the future group to be reverse, will eventually hit end of list 

    
    while(nextAnchor != nullptr){
        
        // Find the node beginning of the next group
        // We will only reverse nodes before this node
        counter = 0;
        while(counter < k && nextAnchor != nullptr){
            counter++;
            if(counter == k){
                tmp = nextAnchor; // Needed in order to isolate left end of portion being reversed
            }
            nextAnchor = nextAnchor->next;
        }
    
        revHead = currAnchor->next;            // Group to be reversed: head
        revRunner = currAnchor->next->next;    // Group to be reversed: second element
        revAnchor = currAnchor->next;          // Remember this position for remerging
        currAnchor->next = nullptr;            // Group to be reversed: isolate start
        if(tmp != nullptr) tmp->next = nullptr;// Group to be reversed: isolate end
        
        
        // Perform reversion
        revHead->next = nullptr; // split group in two
        while(revRunner != nullptr){
            tmp = revRunner->next;     // save next item
            revRunner->next = revHead; // grow reversed list
            revHead = revRunner;       // adjust to head of grown reversed list
            revRunner = tmp;           // position runner for next item
        }
    
        currAnchor->next = revHead;    // Merge bigger list with head of reversed
        revAnchor->next = nextAnchor;  // Merge end of reversed with bigger list
        currAnchor = revAnchor;        // Grow List to be returned
    }      
    
    return dummy->next;
}


// Driver program to test above functions 
int main() 
{ 
    vector<int> data {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *root = new Node(data[0]), *curr; 
    curr = root;
    
    for(int i = 1; i < data.size(); i++){
        curr->next = new Node(data[i]);
        curr = curr->next;
    }
    curr->next = nullptr;

    // Let us flatten the list 
    root = reverse(root, 3); 

    // Let us print the flatened linked list 
    printList(root); 

    return 0; 
} 

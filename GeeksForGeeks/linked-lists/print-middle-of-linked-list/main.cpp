
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

int printMiddle(Node* head) {
    // Your Code Here
    
    // Handle null case and single case
    if(head == nullptr) return 0;
    if(head->next == nullptr) return head->data;
    
    // Handle all other cases
    Node *dummy = new Node(0);
    dummy->next = head;
    
    Node *slow = dummy, *fast = dummy;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow->next = slow->next->next;
    
    return slow->next->data;
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
    int m = printMiddle(root); 

    // Let us print the flatened linked list 
    printf("\n");
    printf("%d ", m); 

    return 0; 
} 


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



int getNthFromLast(Node *head, int n)
{
    Node *dummy = new Node(0), *ahead = dummy, *behind = dummy;
    dummy->next = head;
    int counter = n;
    
    while(ahead != nullptr && counter-- > 0) ahead = ahead->next; 
    if(ahead == nullptr) return -1;
    
    while(ahead != nullptr){
        ahead = ahead->next;
        behind = behind->next;
    }

    return behind->data;
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
    int res = getNthFromLast(root, 4); 

    // Let us print the flatened linked list 
    assert(res == data[data.size() - 4]);
    printf("\n%d\n", res);
    printList(root); 

    return 0; 
} 

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

Node *rotateList(Node *root, int k)
{
    if(root == nullptr) return nullptr;
    if(k <= 0) return root;
   
    Node *newHead; 
    Node *runner = root;  
    int counter;

    counter = 1;
    while(counter < k && runner->next != nullptr){
        runner = runner->next;
        counter++;
    }
    newHead = runner->next;
    if(newHead == nullptr) return root;

    runner->next = nullptr;
    runner = newHead;

    while(runner->next != nullptr){
        runner = runner->next;
    }
    runner->next = root;

    return newHead;
}


// Driver program to test above functions 
int main() 
{ 
    vector<int> data {10, 20, 30, 40, 50, 60};
    Node *root = new Node(data[0]), *curr; 
    curr = root;
    
    for(int i = 1; i < data.size(); i++){
        curr->next = new Node(data[i]);
        curr = curr->next;
    }
    curr->next = nullptr;

    // Let us flatten the list 
    root = rotateList(root, 5); 

    // Let us print the flatened linked list 
    printList(root);  

    return 0; 
} 

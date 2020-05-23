
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


bool dfs(Node **head, Node *curr){
    if(curr == nullptr) return true;

    bool match = dfs(head, curr->next) && ((*head)->data == curr->data);
    
    (*head) = (*head)->next;
    return match;
}
int isPalindrom(Node *head){
    return dfs(&head, head);
}




// Driver program to test above functions 
int main() 
{ 
    vector<int> data {1,9,2,9,1};
    Node *root = new Node(data[0]), *curr; 
    curr = root;
    
    for(int i = 1; i < data.size(); i++){
        curr->next = new Node(data[i]);
        curr = curr->next;
    }
    curr->next = nullptr;

    // Let us flatten the list 
    bool res = isPalindrom(root); 

    // Let us print the flatened linked list 
    assert(res == true);
    printf("\n%d\n", res);
    printList(root); 

    return 0; 
} 

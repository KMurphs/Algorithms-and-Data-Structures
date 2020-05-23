
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

Node *removeloop(Node *head) {
    
    if(head == nullptr) return head;
    
    Node *fast = head->next;
    Node *slow = head;
    
    while(fast && slow && fast != slow){
        fast = fast->next == nullptr ? nullptr : fast->next->next;
        slow = slow->next;
    }

    if(fast == nullptr || slow == nullptr) return head;
    
    Node *dummy = new Node(0, head);
    Node *tmp = dummy;
    while(tmp->next != slow->next){
        tmp = tmp->next;
        slow = slow->next;
    }
    slow->next = nullptr;

    
    return head;
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
    curr->next = root;

    removeloop(root);
    printList(root); 
    
    curr->next = root->next;

    removeloop(root);
    printList(root); 

    printf("Program exited sucessfully\n");
    cout << "Program exited sucessfully" << endl;
    return 0; 
} 

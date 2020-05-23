
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

int detectloop(Node *head) {
    
    if(head == nullptr) return 0;
    
    Node *fast = head->next;
    Node *slow = head;
    while(fast && slow && fast != slow){
        fast = fast->next == nullptr ? nullptr : fast->next->next;
        slow = slow->next;
    }
    
    return fast != nullptr && slow != nullptr;
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

    int res = detectloop(root);
    assert(res == 0); 
    printf("\n");
    printf("%d\n", res);

    // printList(root); 
    printf("Program exited sucessfully\n");
    cout << "Program exited sucessfully" << endl;
    return 0; 
} 

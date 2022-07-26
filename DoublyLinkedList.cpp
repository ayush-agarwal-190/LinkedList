#include <bits/stdc++.h>
using namespace std;
  
// A linked list node 
class Node 
{ 
    public:
    int data; 
    Node* next; 
    Node* prev; 
}; 
  
/* Given a reference (pointer to pointer) 
to the head of a list 
and an int, inserts a new node on the 
front of the list. */
void push(Node** head, int data) 
{ 
    /* 1. allocate node */
    Node* node = new Node(); 
  
    /* 2. put in the data */
    node->data = data; 
  
    /* 3. Make next of new node as head 
    and previous as NULL */
    node->next = (*head); 
    node->prev = NULL; 
  
    /* 4. change prev of head node to new node */
    if ((*head) != NULL) 
        (*head)->prev = node; 
  
    /* 5. move the head to point to the new node */
    (*head) = node; 
} 
  
/* Given a node as prev_node, insert 
a new node after the given node */
void insertAfter(Node* prev_node, int data) 
{ 
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) 
    { 
        cout<<"the given previous node cannot be NULL"; 
        return; 
    } 
  
    /* 2. allocate new node */
    Node* node = new Node();
  
    /* 3. put in the data */
    node->data = data; 
  
    /* 4. Make next of new node as next of prev_node */
    node->next = prev_node->next; 
  
    /* 5. Make the next of prev_node as new_node */
    prev_node->next = node; 
  
    /* 6. Make prev_node as previous of new_node */
    node->prev = prev_node; 
  
    /* 7. Change previous of new_node's next node */
    if (node->next != NULL) 
        node->next->prev = node; 
} 
  
/* Given a reference (pointer to pointer) to the head 
of a DLL and an int, appends a new node at the end */
void append(Node** head, int data) 
{ 
    /* 1. allocate node */
    Node* node = new Node(); 
  
    Node* last = *head; /* used in step 5*/
  
    /* 2. put in the data */
    node->data = data; 
  
    /* 3. This new node is going to be the last node, so 
        make next of it as NULL*/
    node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new 
        node as head */
    if (*head == NULL)
    { 
        node->prev = NULL; 
        *head = node; 
        return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
  
    /* 6. Change the next of last node */
    last->next = node; 
  
    /* 7. Make last node as previous of new node */
    node->prev = last; 
  
    return; 
} 
  
// This function prints contents of 
// linked list starting from the given node 
void printList(Node* node) 
{ 
    Node* last; 
    cout<<"\nTraversal in forward direction \n"; 
    while (node != NULL) 
    { 
        cout<<" "<<node->data<<" "; 
        last = node; 
        node = node->next; 
    } 
  
    cout<<"\nTraversal in reverse direction \n"; 
    while (last != NULL) 
    { 
        cout<<" "<<last->data<<" "; 
        last = last->prev; 
    } 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL; 
  
    // Insert 6. So linked list becomes 6->NULL 
    append(&head, 6); 
  
    // Insert 7 at the beginning. So 
    // linked list becomes 7->6->NULL 
    push(&head, 7); 
  
    // Insert 1 at the beginning. So 
    // linked list becomes 1->7->6->NULL 
    push(&head, 1); 
  
    // Insert 4 at the end. So linked 
    // list becomes 1->7->6->4->NULL 
    append(&head, 4); 
  
    // Insert 8, after 7. So linked 
    // list becomes 1->7->8->6->4->NULL 
    insertAfter(head->next, 8); 
  
    cout << "Created DLL is: "; 
    printList(head); 
  
    return 0; 
} 
  
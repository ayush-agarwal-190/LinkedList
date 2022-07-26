#include <iostream>
 
using namespace std;
 
struct node {
 
    int data;
 
    node* next;
 
    node(int x)
    {
 
        data = x;
 
        next = NULL;
    }
};
 
void insertAtTail(node*& head, int x)
{
 
    if (head == NULL) {
 
        head = new node(x);
 
        return;
    }
 
    node* curr = head;
 
    while (curr->next != NULL) {
 
        curr = curr->next;
    }
 
    node* t = new node(x);
 
    curr->next = t;
}
 
void print(node* head)
{
 
    node* curr = head;
 
    while (curr != NULL) {
 
        cout << curr->data << " -> ";
 
        curr = curr->next;
    }
   cout << "NULL\n";
}
 
node* appendK(node* head, int k)
{
 
    node* fast = head;
 
    node* slow = head;
 
    for (int i = 0; i < k; i++) {
 
        fast = fast->next;
    }
 
    while (fast->next != NULL) {
 
        slow = slow->next;
 
        fast = fast->next;
    }
 
    // cout<<"data"<<" "<<slow->data<<" "<<fast->data<<endl;
 
    fast->next = head;
 
    head = slow->next;
 
    slow->next = NULL;
 
    return head;
}
 
int main()
{
 
    node* head = NULL;
 
    int n;
    n = 6 ;
 
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
 print(head);
    int k;
 
    k = 3 ;
 
    head = appendK(head, k % n);
 
    print(head);
 
    return 0;
}
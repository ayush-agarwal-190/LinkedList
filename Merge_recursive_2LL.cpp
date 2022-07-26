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
 
node* mergeRecursive(node* &head1, node* &head2)
{
    if(head1==NULL)
      return head2;
    if(head2==NULL)
      return head1;
    node* result;
    if(head1->data<head2->data)
    {
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else
    {
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result; 
}
 
int main()
{
 
    node* head1 = NULL;
    node* head2 = NULL;
 int arr1[]={1,4,5,7};
 int arr2[]={2,3,6};
 for(int i=0;i<4;i++)
  insertAtTail(head1,arr1[i]);
 for(int i=0;i<3;i++)
  insertAtTail(head2,arr2[i]);

  print(head1);
  print(head2);
 node* newhead=mergeRecursive(head1,head2);
 print(newhead);
    return 0;
}
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
 
node* merge(node* &head1, node* &head2)
{
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;

    }
    while(p1!=NULL)
    {
       p3->next=p1;
       p1=p1->next;
       p3=p3->next;    
    }
    while(p2!=NULL)
    {
       p3->next=p2;
       p2=p2->next;
       p3=p3->next;    
    }
    return dummyNode->next;
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
 node* newhead=merge(head1,head2);
 print(newhead);
    return 0;
}
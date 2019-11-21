#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
node* insert(struct node* head,int data)
{
	struct node* p;
	p=new(struct node);
	p->data=data;
	p->next=NULL;
	struct node* temp=head;
	if(head!=NULL)
	{
   while(temp->next!=NULL)
   temp=temp->next;
   temp->next=p;
   p->prev=temp;
   p->next=NULL;
   }
   else
   {
   	p->prev=NULL;
   	head=p;
   }
   return head;
}
void display(struct node* head)     //insert a node at the beginning of DLL. 
{
	struct node* temp=head;
	while(temp!=NULL) 
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
node* reverse(struct node* head)
{
	struct node* temp=NULL;             //reverse a doubly linked list.  complexity -O(n).
	struct node* curr=head;
	while(curr!=NULL)
	{
		temp=curr->prev;
		curr->prev=curr->next;
		curr->next=temp;
		curr=curr->prev;
	}
	head=temp->prev;
	return head;
}
int main()
{
	struct node* head=NULL;
	head=insert(head,10);
	head=insert(head,20);
	head=insert(head,30);
	head=insert(head,40);
	struct node * g=reverse(head);
	display(g);
	return 0;
}

#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	struct node* next;
	struct node* prev;
	int data;
};
node* insert(struct node* head,int data)
{
	struct node* p;
	p=new (struct node);
	p->data=data;
	p->prev=NULL;
	p->next=head;
	if(head!=NULL)
	{
	  head->prev=p;
	  p->next=head;
	}
		head=p;
		return head;
}
void insertaf(struct node* pre,int data)
{
	if(pre==NULL)
	return;
	struct node* p=new (struct node);
	p->data=data;
	p->next=pre->next;
	pre->next=p;
	p->prev=pre;
	if(pre!=NULL)
	{
		p->next->prev=p;
	}
}
void display(struct node* head)
{
	struct node* g=head;                         //insert node after a prev node in doubly linked list.
	while(g!=NULL)
	{
		cout<<g->data<<" ";
		g=g->next;
	}
}
int main()
{
	struct node* head=NULL;
     head=insert(head,10);
     head=insert(head,20);
     head=insert(head,30);
     head=insert(head,40);
     insertaf(head->next->next,28);
     display(head);
     return 0;
}

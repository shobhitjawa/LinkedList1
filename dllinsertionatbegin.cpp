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
	p->next=head;
	p->prev=NULL;
	if(head!=NULL)
	{
		head->prev=p;
	}
	head=p;
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
int main()
{
	struct node* head=NULL;
	head=insert(head,10);
	head=insert(head,20);
	head=insert(head,30);
	head=insert(head,40);
	display(head);
	return 0;
}

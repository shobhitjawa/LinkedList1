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
	struct node* p=new(struct node);
	 p->next=head;
	 p->prev=NULL;
	 p->data=data;
	 if(head!=NULL)
	 {
	 	head->prev=p;
	 	p->next=head;
	 }
	 else{
	    p->next=NULL;
	 }
	 head=p;
}
void deleten(struct node** head,struct node* del)
{
	if(*head==NULL)
	return;
	if(del==*head)
	{
		*head=(*head)->next;
	}
	if(del->next!=NULL)
	del->next->prev=del->prev;
	if(del->prev!=NULL)
	del->prev->next=del->next;
	delete(del);
}
void display(struct node* head)
{                                         //delete a node in a linked list time complexity-- O(1).
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
	deleten(&head,head->next);
	display(head);
	return 0;
}

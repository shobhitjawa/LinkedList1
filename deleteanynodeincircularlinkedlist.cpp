#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	struct node* next;
	int data;
};
void insert(struct node** head,int data)
{
	struct node* p=new(struct node);
	p->data=data;
	p->next=*head;
	struct node* temp=*head;
	if(*head!=NULL)
	{
		while(temp->next!=*head)
		temp=temp->next;
    p->next=*head;
    *head=p;                   //delete node from a doubly linked list.
    temp->next=*head;
    
	}
	else
	{
		p->next=p;
		*head=p;
	}
}
node*  delet(struct node* head,int key)
{
	struct node* temp=head->next;
	if(head==NULL)
	{
		return NULL;
	}
	if(head->data==key&&head->next==head)
	{
		delete(head);
	    head=NULL;
	}
	struct node* last=head;
	struct node* d;
	if(head->data==key)
	{
		while(last->next!=head)
		last=last->next;
		last->next=head->next;
		delete(head);
		head=last->next;
	}
	 while(last->next!=head&&last->next->data!=key) { 
        last=last->next; 
    } 
    if(last->next->data==key) { 
        d=last->next; 
        last->next=d->next; 
        delete(d); 
    } 
    else
        cout<<"no such keyfound";
		return head; 
    } 
    

void display(struct node* head)
{
	struct node* temp=head->next;
	 cout<<head->data<<" ";
	while(temp!=head)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	struct node* head=NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);
	display(head);
	struct node* i=delet(head,3);
	cout<<endl;
	display(i);
	return 0;
}

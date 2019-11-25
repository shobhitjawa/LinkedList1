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
	p->data=data;              //remove from sorted linked list.
	p->prev=NULL;
   if(head!=NULL)
   {
      head->prev=p;
	  p->next=head;
   }
   else
   {
   	p->next=NULL;
   }
   head=p;
    return head;
	 
}
void display(struct node* head)
{
	 struct node* temp=head;
	 while(temp!=NULL)
	 {
	 	cout<<temp->data<<" ";
	 	temp=temp->next;
	 }
}
void removeduplicates(struct node** head)
{
	if(*head==NULL)
	return;
	struct node* temp=*head;
		struct node* r;
			struct node* v;
	while(temp->next!=NULL)
	{
		if(temp->data==temp->next->data)
		{
			r=temp->next;       
			if(r==NULL)
			return;
		   if(r==*head)
		   {
		   	*head=r->next;
		   }
		   if(r->next!=NULL)
		   {
		   r->next->prev=r->prev;
	       }
		   if(r->prev!=NULL)
		   {
		   r->prev->next=r->next;
	        }
		   if(r->next==NULL)
		   {
		   	r->prev->next=NULL;
		   }
		   delete(r);
		}
		else
		{
			temp=temp->next;
		}
	}
}
int main(){
	struct node* head=NULL;
	 head=insert(head,10);
	 head=insert(head,10);
	 head=insert(head,20);
    head=insert(head,30);
    head=insert(head,30);
     head=insert(head,30);
     head=insert(head,40);
      head=insert(head,40);
      head=insert(head,50);
//	display(head);
	removeduplicates(&head);
		display(head);
	return 0;
}



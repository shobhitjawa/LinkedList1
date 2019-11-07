#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
struct node{
	int data;
	struct node* next;
};
node* createnode(int data)
{
	struct node* p;
	p=new(struct node);
   p->data=data;
   p->next=NULL;
   return p;
}
void insert(struct node** head,int a)
{
	struct node* p;
	p=createnode(a);
	if(*head==NULL)
	{
		*head=p;
		p->next=NULL;
	}
	else
	{
		struct node* y=*head;
		while(y->next!=NULL)
		{
			y=y->next;
		}
	    y->next=p;
	    p->next=NULL;
	}
}
void removeduplicate(struct node* head){
   struct node* v;
   if(head==NULL)
   {
   	return;
   }                      //remove dupicate from sorted linked list recursively.
   if(head->next!=NULL)
   {
   	if(head->data==head->next->data)
   	{
   	v=head->next;
   	head->next=head->next->next;
   	delete(v);
   	removeduplicate(head);
	   }
	   else{
	   	removeduplicate(head->next);
	   }
   }
} 
void display(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
int main()
{
	struct node* head=NULL;
	int n;                                        //remove duplicates from sorted linked list.
	cin>>n;
	int number;
	for(int i=0;i<n;i++)
	{
		cin>>number;
		insert(&head,number);
	}
	//display(head);
	removeduplicate(head);
		display(head);
	return 0;
}


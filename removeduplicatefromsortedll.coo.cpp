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
    struct node* curr=head;
    struct node* v;
    while(curr->next!=NULL)
    {
    	if(curr->data==curr->next->data)
    	{
    		v=curr->next->next;
    		delete(curr->next);
    		curr->next=v;
		}
		else
		{		
		curr=curr->next;
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
	int n;                                        //remove duplicates from sorted linked list. timd complexity-O(n).
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


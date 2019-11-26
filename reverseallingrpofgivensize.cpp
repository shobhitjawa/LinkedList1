#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
node* insert(struct node* head,int data)
{
	struct node* temp=head;
	struct node* p;
	p=new (struct node);
	p->next=NULL;
	p->data=data;
     if(head!=NULL)
     {
     	p->next=head;
     	head=p;
	 }
	 else
	 {
	 	p->next=NULL;
	 	head=p;
	 }
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
node* reverse(struct node* head,int k)
{
	struct node* curr=head;
	struct node* agla=NULL;
	struct node* pichla=NULL;
	int count=0;
	 while(curr!=NULL&&count<k)
	 {
	 	agla=curr->next;
	 	curr->next=pichla;
	 	pichla=curr;
	 	curr=agla;
	 	count++;
	 }                                        //reverse a linked list in a group of given size.
	 if(agla!=NULL)
	 {
	 	head->next=reverse(agla,k);
	 }
	 return pichla;
}
int main()
{
	struct node* head=NULL;
	head=insert(head,10);
	head=insert(head,12);
	head=insert(head,1);
	head=insert(head,3);
	head=insert(head,35);
		display(head);
		cout<<endl;
	struct node* h=reverse(head,2);
	display(h);
	return 0;
}

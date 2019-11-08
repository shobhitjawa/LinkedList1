#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	struct  node* next;
	int data;
};
node* createnode(int data){
  struct node* p;
  p=new (struct node);
  p->data=data;
  p->next=NULL;
  return p;
}
void insert(struct node** head,int r)
{
		struct node *p,*y;
	p=createnode(r);
	if(*head==NULL)
	{
		
		*head=p;
		p->next=NULL;
	}                                                 //move last element to first Complexity--O(n).
	else                                               
	{
		y=*head;
		while(y->next!=NULL)
		{
			y=y->next;
		}
		y->next=p;
		p->next=NULL;
	}
}
void display(struct node* head)
{
	struct node *text=head;
	while(text!=NULL)
	{
		cout<<text->data;
		text=text->next;
	}
	cout<<endl;
}                                  
node* reverse(struct node *head)  
{  
  struct node* curr=head;
  struct node* prev=NULL;
  struct node* agla=NULL;
  while(curr!=NULL)
  {
  	agla=curr->next;
  	curr->next=prev;
  	prev=curr;
  	curr=agla;
  }
  head=prev;
  return head; 
}   
int main()
{
	int n,number;                //reverse a linked list complexity O(n).
	struct node *head=NULL;
	cin>>n;
	int d;
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	display(head);
cout<<"new linked list is ";
struct node* o=reverse(head);
	display(o);
return 0; 
}

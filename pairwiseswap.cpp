#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	struct  node* next;
	int data;
};
node* createnode(int data){                 //this is wrong code not executing...
	
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
	}                                                     
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
void pairwiseswap(struct node* head)
{                                              //pairwise swap a linked list.
	struct node* temp=head;
	struct node* temp1=temp->next;
	while(temp!=NULL&&temp1->next!=NULL)
	{
		swap(temp->data,temp1->data);
		temp=temp->next->next;
		temp1=temp->next;
	}
	swap(temp->data,temp1->data);
}
void swap(int a,int b)
{
	int c;
	c=a;
	a=b;
	b=c;
}
int main()
{
	int n,number,number1,d;               
	struct node *head=NULL;
	struct node *head1=NULL;
	cout<<"enter number of elements in linked list 1.";
	cin>>n;
	cout<<"first linked list"<<endl;
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	pairwiseswap(head);
	display(head);
return 0; 
}

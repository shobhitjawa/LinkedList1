#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	struct node* next;
	int data;
};
node* createnode(int data)
{
     struct node* p;
	 p=new (struct node);
	 p->data=data;
	 p->next=NULL;
	 return p;
}
void insert(struct node **head,int num)
{
	struct node *p,*y;
	p=createnode(num);
	if(*head==NULL)
	{
		
		*head=p;
		p->next=NULL;
	}
	else                                               //insert at end of linked list.
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
node* movelasttofirst(struct node* head)
{
 struct node* last=head;
 struct node* secondlast=head;
 struct node* p=head;
 while(last->next!=NULL)
 {
   secondlast=last;
 	last=last->next;                                 //move last to first in linked list.
 } 
 secondlast->next=NULL;
 last->next=head;
 p=last;
 return head;
}
int main()
{
	int n,number;
	struct node *head=NULL;
	cin>>n;
	
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	} 
	cout<<endl; 
struct node* y=	movelasttofirst(head); 
while(y!=NULL)
{
	cout<<y->data<<" ";
	y=y->next;
  }  
return 0;
}

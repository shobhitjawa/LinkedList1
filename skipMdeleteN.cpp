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
{                                                   //skip M delete N in linked list.
	struct node *text=head;
	while(text!=NULL)
	{
		cout<<text->data;
		text=text->next;
	}
	cout<<endl;
}
void skipMdeleteN(struct node* head,int m,int n)
{
	if(head==NULL)
	{
		return;
	}
	struct node* temp=head; 
	struct node* curr=head;
	struct node* r1=NULL;
	struct node* r2=NULL;
	struct node* temp1;
	struct node* temp2=NULL;
	while(curr!=NULL)
	{ 
	int countm=0;
	while(temp!=NULL&&countm<m)
	{ 
		if(r1==NULL)
		{
			r1=temp;
			r2=r1;
		}
		else{
		   r1->next=temp;
		   r1=r1->next;	
		  }
		  temp1=temp;
		temp=temp->next;
		countm++;
	}    
	 temp2=temp1->next; 
      int countn=0;
      if(temp2!=NULL)
      {
	while(temp2!=NULL&&countn<n)
	{
		struct node* f;
		f=temp2;
		temp2=temp2->next;
         delete(f);	
		countn++;
	} 
	curr=temp2;
	temp1->next=temp2;
	temp=temp2;
    }
	else{
		curr=temp1;
	} 
}
while(r2!=NULL)
	{
		cout<<r2->data<<" ";
		r2=r2->next;
	 } 
}
int main()
{
	int a,number;
	struct node *head=NULL;
	cin>>a;
	
	for(int i=a;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	} 
	int m=2;
	int n=3;
	skipMdeleteN(head,m,n); 
return 0;
}

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
void insertinbetween(struct node** head,int x,int y)
{
	struct node* temp1=*head;
	struct node* temp2;
	struct node* temp3=createnode(y);
	while(temp1->next!=NULL)
	{
		if(temp1->data==x)
		{
			temp2=temp1;
			break;
		}
		temp1=temp1->next;
	}
	temp1=temp2->next;
//	cout<<temp3->data;            //insert node in between a certain node.
	temp2->next=temp3;
	temp3->next=temp1;
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
int main()
{
	int n,number;
	struct node *head=NULL;
	cin>>n;
	int x;
	int y;
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	display(head);
		cout<<"enter the number after which you want to insert your  new node";
	cin>>x;
	cout<<"enter the value ";
	cin>>y;
	insertinbetween(&head,x,y);
	display(head);
return 0;
}

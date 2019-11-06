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
void getNthnodelast(node* head, int index)  
{  
     int count=0; 
    node* current =head;  
    while(current!=NULL)
	{
	  count++;
	  	current=current->next;
	}  
	if(index>count)
	{
		return ;
	}
	current=head;
	for(int i=0;i<count-index-1;i++)
	{
		current=current->next;
	}
	cout<< current->data; 
}  
int main()
{
	int n,number;
	struct node *head=NULL;
	cin>>n;
	int d;
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	display(head);
	int m;
	cin>>m;
cout<<"mth node value is";
getNthnodelast(head,m);
return 0; 
}

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
}                                  //search a element in a linked list
int count(struct node* head)
{
	if(head==NULL)
	{
		return 0;
	}
	return 1+count(head->next);
}
bool search(struct node* head,int x)
{
	struct node* curr=head;
	while(curr!=NULL)
	{
		if(curr->data==x)
			return true;
			curr=curr->next;
	}
	return false;
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
	cout<<"count is "<<count(head);
	cin>>d;
	bool f=search(head,d);
    if(f==1)
    cout<<"true";
    else
    cout<<"false";
return 0;
}

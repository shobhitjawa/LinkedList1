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
	p=new(struct node);
	p->data=data;
	p->next=NULL;
	return p;
}
void insert(struct node **head,int num)
{
	struct node *p;
	p=createnode(num);
	if(*head==NULL)
	{
		
		*head=p;
		p->next=NULL;
	}
	else
	{
		p->next=*head;
		*head=p;
	}
}
int count(struct node** head)
{
	int count=0;
	struct node* temp=*head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
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
}                                                //number of nodes in ll.
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
	display(head);

  int f=count(&head);
  cout<<f;
return 0;
}

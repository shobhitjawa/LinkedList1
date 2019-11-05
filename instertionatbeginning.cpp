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
node* insert(struct node** head,int data)
{
	struct node* temp;
	temp=createnode(data);
	if(*head==NULL)
	{
		*head=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=*head;
		*head=temp;
	}
	return temp;
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
	
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	display(head);
return 0;
}

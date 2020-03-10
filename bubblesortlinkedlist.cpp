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
	temp=createnode(data);                      //bubble sort a linked list Complexity- O(n).
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
node* bubblesort(struct node* head)
{
	int x;
	struct node* temp=head;
	while(temp!=NULL)
	{
		struct node* temp1=temp->next;
		while(temp1!=NULL)
		{
			if(temp->data>temp1->data)
			{
				x=temp->data;
				temp->data=temp1->data;
				temp1->data=x;
			}
			temp1=temp1->next;
		}
		temp=temp->next;
	}
	return head;
}
void display(struct node* head)
{
	struct node *text=head;
	while(text!=NULL)
	{
		cout<<text->data<<" ";
		text=text->next;
	}
	cout<<endl;
}
int main()
{
	int n,number;
	struct node *head=NULL;
	cin>>n;                 //bubble sort a linked list .
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	display(head);
	struct node* t=bubblesort(head);
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
return 0;
}

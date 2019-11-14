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
}                                  //convert  a singly linked list to doubly linked list.
void display(struct node* head)
{
 struct node *temp = head;  
    if (temp != NULL)  
    { 
        do
        { 
            cout<<temp->data; 
            temp = temp->next; 
        } 
        while (temp != head); 
    } 
}
void convert(struct node* head)
{
	struct node* temp=head;
  while(temp->next!=NULL)
  {
  	temp=temp->next;
  }
  temp->next=head;
}
int main()
{
	struct node* head=NULL;
		int n,number;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>number;
		insert(&head,number);
}
convert(head);
	display(head);
	return 0;
}

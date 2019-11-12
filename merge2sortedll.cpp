#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	struct  node* next;
	int data;
};
node* createnode(int data){
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
node* sortedmerge(struct node* head,struct node* head1)
{
	struct node* result=NULL;
	if(head==NULL)
	return head1;
	if(head1==NULL)
	return head;
	if(head->data<=head1->data)
	{
		result=head;
		result->next=sortedmerge(head->next,head1);
	}
	else
	{
		result=head1;
		result->next=sortedmerge(head,head1->next);
	}
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
	cout<<"enter number of elements in linked list 2";
      cin>>d;
	for(int i=0;i<d;i++)
	{
		cin>>number1;
		insert(&head1,number1);
	}
	sortedmerge(head,head1);
	display(head);
return 0; 
}

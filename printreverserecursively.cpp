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
	}                                                      //reverse a linked list using recursion.O(n).
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
void printreverse(struct node *head)  
{  
  if(head==NULL)
  return;
  printreverse(head->next);
  cout<<head->data;
}   
int main()
{
	int n,number,number1;               
	struct node *head=NULL;
	cout<<"enter number of elements in linked list 1.";
	cin>>n;
	cout<<"first linked list"<<endl;
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	printreverse(head);
//	display(head);
return 0; 
}

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
	}                                                 //move last element to first Complexity--O(n).
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
void printMiddle(struct node **head)  
{  
  struct node* temp=*head;
   struct node* temp2=*head;
  struct node* temp1;
  struct node* seclast;
  while(temp2->next!=NULL)
  {
  	seclast=temp2;
  	temp2=temp2->next;
  }
   while(temp!=NULL)
   {
   	temp1=temp;
   	temp=temp->next;
   }
  seclast->next=NULL;
  temp1->next=*head;
  *head=temp1;
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
cout<<"new linked list is ";
printMiddle(&head);
	display(head);
return 0; 
}

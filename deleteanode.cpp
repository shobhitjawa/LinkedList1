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
void remove(struct node** head,int v){
	struct node* temp1=*head;
	struct node* temp2;
	int a=temp1->data;
		struct node* temp3;
	struct node* r=*head;
	if(temp1==NULL)
	return;
	if(a==v)
	{
		delete(temp1);
		cout<<"deleted sucessfully..";
	}
	while(temp1->next!=NULL)
	{
		if(temp1->data==v)
		{
			temp2=temp1;                    //delete a particular node in linked list.
			break;
		}
		r=temp1;
		temp1=temp1->next;
	}
	temp3=temp2->next;
//	cout<<temp3->data<<endl<<r->data;
	r->next=temp3;
	delete(temp2);
	
}
int main()
{
	int n,number;
	struct node *head=NULL;
	cin>>n;
	int v;
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	display(head);
	cout<<"enter the node u want to delete";
	cin>>v;
	remove(&head,v);
		display(head);
return 0;
}

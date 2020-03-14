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
  struct node* mergesorted(struct node* a,struct node* b)
  {
  	 node* result = NULL;  
    if(a==NULL&&b==NULL)
	{
		return NULL;
	}
	else if(a==NULL)
	{
		return b;
	 }
	 else if(b==NULL)
	 {
	 	return a;
	 }
	 	 if (a->data <= b->data)  
    {  
        result = a;  
        result->next = mergesorted(a->next, b);  
    }  
    else
    {  
        result = b;  
        result->next = mergesorted(a, b->next);  
    }  
		 
		return result;
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
	int n,number,number1;
	struct node* a=NULL;
	struct node* b=NULL;
	cin>>n;
	cout<<"enter first linked list values:";
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&a,number);
	}
	cout<<"next";
	int m;
	cin>>m;
	cout<<"enter values for second linked list";
		for(int i=m;i>0;i--)
	{
		cin>>number1;
		insert(&b,number1);
	}
	struct node* result=mergesorted(a,b);
	display(result);
return 0;
}

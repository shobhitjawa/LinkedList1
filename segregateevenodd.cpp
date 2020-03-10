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
	p=createnode(num);                             //segregate even and odd in linked list. -(O'n')-->time complexity.
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
void segregateoddeven(struct node** head)
{
   struct node* curr=*head;
   struct node* curr1=*head;
   struct node* even=NULL;
      struct node* p=NULL;
      struct node* t=NULL;
   struct node* odd=NULL; 
   while(curr!=NULL)
   {
   	if(curr->data%2==0)
   	{
	   
     if(even==NULL)
     {
     	even=curr;
        p=even;
	 }
	 else{
	 	even->next=curr;
	 	even=even->next;
	 }
    }
    else{
    	if(odd==NULL)
    	{
    		odd=curr;
    		t=odd;
		}
		else{
			odd->next=curr;
			odd=odd->next;
		}
	}
	 curr=curr->next;
} 
 even->next=t;
 odd->next=NULL;
 while(p!=NULL)
 {
 	
 	cout<<p->data<<" ";
 	p=p->next;
 }
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
	cout<<endl; 
  segregateoddeven(&head);  
return 0;
}

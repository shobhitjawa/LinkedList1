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
void detectloop(struct node *head)  
{  
int flag=0;
    struct node *slow_ptr = head;  
    struct node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
            if(fast_ptr==slow_ptr)
            {
            	flag=1;
            	break;
			}
        }  
        if(flag==1)
		{
			cout<<"loop detected";
		 } 
		 else
		 {
		 	cout<<"loop undetected";
		 }
    }  
}   
int main()
{
	int n,number;
	struct node *head=NULL;
		
		insert(&head,1);
		insert(&head,2);
		insert(&head,3);
		insert(&head,4);
		insert(&head,5);
		insert(&head,6);
		display(head);
		head->next->next->next->next=head;
detectloop(head);
return 0; 
}

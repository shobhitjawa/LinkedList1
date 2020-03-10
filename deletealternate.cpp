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
	 p->next=NULL;                      //time complexity-O(n) n is is length of ll
	 return p;                               //space complexity-O(1)
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
	}                                        //delete alternate
	cout<<endl;
}                                  
node* deletealternatenode(struct node* head)
{
 if(head==NULL)
 return NULL;
 
 struct node* temp=head;
 struct node* del;
 del=temp->next;
 while(temp!=NULL&&del!=NULL)
 { 
 	temp->next=del->next;
 	delete(del);
    temp=temp->next;                //delete alternate node of linked list.
    	if(temp!=NULL)
    	{
    		del=temp->next;
		}
 }
     	return head;
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
	// 	insert(&head,7);
		display(head);
       struct node* tp= deletealternatenode(head);
       while(tp!=NULL)
       {
       	cout<<tp->data<<" ";
       	tp=tp->next;
	   }
return 0; 
} 


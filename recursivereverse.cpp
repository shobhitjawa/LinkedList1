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
	}                                        //reverse recursively.
	cout<<endl;
}                                  
void reverserecursive(struct node* head)
{
if(head!=NULL)
{
 	reverserecursive(head->next);
 	cout<<head->data<<" ";
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
        reverserecursive(head);
return 0; 
} 


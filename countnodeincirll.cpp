#include<stdio.h>
#include<iostream>
using namespace std;
struct node{
	struct node* next;
	int data;
};
void insert(struct node** head,int data)
{
	struct node* ptr1=new (struct node);
	ptr1->data=data;
	ptr1->next=*head;                                     //insert element in a circular linkedlist
	struct node* temp=*head;
	
	if(*head!=NULL)
	{
				while(temp->next!=*head)
	{
		temp=temp->next;
	} 
	ptr1->next=*head;
	*head=ptr1;
	temp->next=*head;
	}
	else
	{
     ptr1->next=ptr1;          
     *head=ptr1;
	}               
}
void display(struct node* head)
{
	int  c=0;
 struct node *temp = head->next;  
    if (head != NULL)  
    {  
      //cout<<head->data<<" ";
        while (temp != head)                //count nodes in a circular linked list.
		{
		//	cout<<temp->data<<" ";
		c++;
			temp=temp->next;
		  }  
    }
	cout<<c+1;  
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
	display(head);
	return 0;
}

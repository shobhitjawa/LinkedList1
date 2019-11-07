#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
struct node{
	int data;
	struct node* next;
};
node* createnode(int data)
{
	struct node* p;
	p=new(struct node);
   p->data=data;
   p->next=NULL;
   return p;
}
void insert(struct node** head,int a)
{
	struct node* p;
	p=createnode(a);
	if(*head==NULL)
	{
		*head=p;
		p->next=NULL;
	}
	else
	{
		struct node* y=*head;
		while(y->next!=NULL)
		{
			y=y->next;
		}
	    y->next=p;
	    p->next=NULL;
	}
}
bool isPalin(node* head){
        node* slow= head; 
        stack <int> s;             //check if a linked list  is  palindrome.
        while(slow != NULL){ 
                s.push(slow->data);
                slow = slow->next; 
        } 
        while(head != NULL ){  
             int i=s.top(); 		   
             s.pop(); 
            if(head -> data != i){ 
                return false; 
            } 
           head=head->next; 
        } 
  
return true; 
} 
void display(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
int main()
{
	struct node* head=NULL;
	int n;
	cin>>n;
	int number;
	for(int i=0;i<n;i++)
	{
		cin>>number;
		insert(&head,number);
	}
	display(head);
	if(isPalin(head)==0)
	{
		cout<<"not a palindrome";
	}
	else{
		cout<<"its a palindrome";
	}
	return 0;
}


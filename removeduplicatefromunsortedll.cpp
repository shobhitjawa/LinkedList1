#include<stdio.h>
#include<iostream>
#include<stack>
#include <bits/stdc++.h> 
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
void removeduplicate(struct node* head){
   struct node* v=head;
   set <int> s1;
   set<int>:: iterator itr; 
   while(v!=NULL)
   {
   	s1.insert(v->data);
   	v=v->next;
   }
    for (itr = s1.begin(); itr != s1.end(); itr++) 
        cout << *itr << " "; 
}                                                         //remove duplicates from unsorted ll and then sort it. time complexity-O(n).
void display(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
	//	cout<<temp->data;
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
	
	removeduplicate(head);
		display(head);
	return 0;
}


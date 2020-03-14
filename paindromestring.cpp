#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	struct node* next;
  string data;
};
node* createnode(string data)
{
     struct node* p;
	 p=new (struct node);
	 p->data=data;
	 p->next=NULL;
	 return p;
}
void insert(struct node **head,string num)
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
			y=y->next;                       //palindrome string.
		}
		y->next=p;
		p->next=NULL;
	}
}
string display(struct node* head)
{
    string d="";
	struct node *text=head;
	while(text!=NULL)
	{
		d=d+text->data; 
		text=text->next;
	}
	cout<<endl;
	return d;
} 

bool palindromestringlinkedlist(string f)
{
  
}
string reverse(string f)
{
 int n = f.length(); 
    for (int i=0, j=n-1; i<j; i++,j--) 
        swap(f[i], f[j]);
		return f;   
}
int main()
{
	int n,number;
	struct node *head=NULL; 
     insert(&head,"a");
     insert(&head,"b");
     insert(&head,"a"); 
	string f=display(head);
	string g=reverse(f);
	cout<<g;
   cout<<f;
     if(g==f)
     {
     	cout<<"done";
	 }
	 else{
	  cout<<"not done";
	 }
	palindromestringlinkedlist(f);
return 0;
}

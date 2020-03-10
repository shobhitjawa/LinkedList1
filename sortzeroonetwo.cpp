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
node* insert(struct node** head,int data)
{
	struct node* temp;
	temp=createnode(data);                      //bubble sort a linked list Complexity- O(n).
	if(*head==NULL)
	{
		*head=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=*head;
		*head=temp;
 	}
	return temp;
} 
void sortList(node *head)  
{  
    int count[3] = {0, 0, 0};   
    node *ptr = head;   
    while (ptr != NULL)  
    {  
        count[ptr->data] += 1;           //sort zero one two in best case complexityh -O(n),space -O(1).
        ptr = ptr->next;  
    }   
    int i = 0;  
    ptr = head;    
    while (ptr != NULL)  
    {  
        if (count[i] == 0)  
            ++i;  
        else
        {  
            ptr->data = i;  
            --count[i];  
            ptr = ptr->next;  
        }  
    }  
}  
  
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
	int n,number;
	struct node *head=NULL;
	cin>>n;
	
	for(int i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	//display(head);
	 sortzeroonetwo(head);
	 //display(head);
 
return 0;
}

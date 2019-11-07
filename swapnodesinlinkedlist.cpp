#include<bits/stdc++.h> 
using namespace std; 
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
struct Node *newNode(int data) 
{ 
   Node *temp = new Node; 
   temp->data = data; 
   temp->next = NULL; 
   return temp; 
} 
void swapnodesinlinkedlist(struct Node** head,int x,int y) 
{
	struct Node* temp1=*head;
			struct Node*prev1=NULL;
				struct Node* temp=*head;
	struct Node*prev=NULL;
	struct Node* p=NULL;
	if(x==y)
	return;
	
	while(temp->data!=x&&temp!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	
	while(temp1->data!=y&&temp1!=NULL)
	{
		prev1=temp1;
		temp1=temp1->next;
	}
    if(prev!=NULL)
    {
    	prev->next=temp1;
	}
	else{
		*head=temp1;
	}
	if(prev1!=NULL){
		prev1->next=temp;
	}
	else
	{
		*head=temp;
	}
	p=temp1->next;
     temp1->next=temp->next;
     temp->next=p;
} 
void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        cout<<node->data<<" "; 
        node = node->next; 
    } 
} 
int main() 
{ 

    struct Node *start = newNode(10); 
    start->next = newNode(11); 
    start->next->next = newNode(14); 
    start->next->next->next = newNode(12); 
    start->next->next->next->next = newNode(18); 
    start->next->next->next->next->next = 
                                    newNode(16); 
    start->next->next->next->next->next->next = 
                                    newNode(21); 
   cout<<"nodes without swapping ..."<<endl;
    printList(start); 
     int x,y;
	 cin>>x>>y; 
    swapnodesinlinkedlist(&start,x,y);
	cout<<"nodes after swapping..."<<endl;
    printList(start); 
  
    return 0; 
}       

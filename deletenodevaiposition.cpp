#include <stdio.h> 
#include <stdlib.h> 
#include<iostream>
using namespace std;
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 

void push(struct Node** head, int data) 
{ 
    struct Node* p = new(struct Node); 
    p->data  = data; 
    p->next =*head; 
    *head= p; 
}
void deleteNode(struct Node **head, int position) 
{ 
 
   if (*head== NULL) 
      return; 
   struct Node* temp = *head; 
    if (position == 0) 
    { 
        *head= temp->next; 
        delete(temp);                
        return; 
    }  
    for (int i=0; temp!=NULL && i<position-1; i++) 
    {
         temp = temp->next; 
     }
    if (temp == NULL || temp->next == NULL) 
         return; 
    struct Node *r = temp->next->next; 
    delete(temp->next);  
  
    temp->next = r; 
} 
void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
       cout<<node->data; 
        node = node->next; 
    } 
} 
int main() 
{
    struct Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8); 
  
    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 4); 
    puts("\nLinked List after Deletion at position 4: "); 
    printList(head); 
    return 0; 
} 

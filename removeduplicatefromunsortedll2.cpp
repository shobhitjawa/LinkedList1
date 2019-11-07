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
void removeDuplicates(struct Node *start) 
{
    set<int> seen;
    struct Node *curr = start; 
    struct Node *prev = NULL; 
    while (curr != NULL) 
    { 
        if (seen.find(curr->data) != seen.end()) 
        { 
           prev->next = curr->next; 
           delete (curr); 
        } 
        else
        { 
           seen.insert(curr->data); 
           prev = curr; 
        } 
        curr = prev->next; 
    } 
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
    start->next = newNode(12); 
    start->next->next = newNode(14); 
    start->next->next->next = newNode(11); 
    start->next->next->next->next = newNode(12); 
    start->next->next->next->next->next = 
                                    newNode(11); 
    start->next->next->next->next->next->next = 
                                    newNode(10); 
  
    cout<<"Linked list before removing duplicates : \n"; 
    printList(start); 
  
    removeDuplicates(start); 
  
    cout<<"\nLinked list after removing duplicates : \n"; 
    printList(start); 
  
    return 0; 
}             //Time complexity O(n).

#include <bits/stdc++.h> 
using namespace std; 
class node { 
public: 
    int data; 
    node* next; 
}; 
node* SortedMerge(node* a, node* b); 
void divide(node* source, 
                    node** frontRef, node** backRef); 
void MergeSort(node** headRef) 
{ 
    node* head = *headRef; 
    node* a; 
    node* b; 
    if ((head == NULL) || (head->next == NULL)) { 
        return;                                //merge sort a linked list.
    } 
    divide(head, &a, &b); 
    MergeSort(&a); 
    MergeSort(&b); 
    *headRef = SortedMerge(a, b); 
} 
node* SortedMerge(node* a, node* b) 
{ 
    node* result = NULL; 
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a);  
     if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 
void divide(node* source, 
                    node** frontRef, node** backRef) 
{ 
    node* fast; 
    node* slow; 
    slow = source; 
    fast = source->next; 
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 
void printList(node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
void push(node** head_ref, int new_data) 
{ 
    node* new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
int main() 
{ 
    node* res = NULL; 
    node* a = NULL; 
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
     cout<<"Unsorted linked list is:";
     printList(a);
     cout<<endl;
    MergeSort(&a);
    cout << "Sorted Linked List is: \n"; 
    printList(a); 
    return 0; 
}  

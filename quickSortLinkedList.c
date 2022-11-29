#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* next;
};
 
void insert(struct node** head, int value)
{
    struct node* new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    
    if (new_node == NULL)
    {
        printf("Memory Overflow!\n");
    }
    else 
    {
        new_node -> data = value;
        new_node -> next = NULL;
        if (*head == NULL) 
        {
            *head = new_node;
        }
        else 
        {
            struct node* temp = *head;
 
            while (temp->next != NULL) 
            {
                temp = temp->next;
            }
 
            temp->next = new_node;
        }
    }
}
 
void printList(struct node* head)
{
    if (head == NULL) 
    {
        printf("The Linked List is Empty!\n");
        return;
    }
    
    struct node* temp = head;
    
    while (temp != NULL) 
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}
 
struct node * last_node(struct node * head)
{
    struct node* temp = head;
    while (temp != NULL && temp->next != NULL) 
    {
        temp = temp->next;
    }
    return temp;
}
 

struct node* parition(struct node* first, struct node* last)
{
    struct node* pivot = first;
    struct node* front = first;
    int temp = 0;
    while (front != NULL && front != last) 
    {
        if (front->data < last->data) 
        {
            pivot = first;
 
            temp = first->data;
            first->data = front->data;
            front->data = temp;
 
            first = first->next;
        }
         front = front->next;
    }
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    
    return pivot;
}
 
void quick_sort(struct node* first, struct node* last)
{
    if (first == last) 
    {
        return;
    }
    struct node* pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) 
    {
        quick_sort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) 
    {
        quick_sort(first, pivot);
    }
}
 

int main()
{
    struct node* head = NULL;
    
    insert(&head, 12);
    insert(&head, 35);
    insert(&head, 82);
    insert(&head, 45);
    insert(&head, 37);
    insert(&head, 59);
    insert(&head, 67);
    insert(&head, 85);
    insert(&head, 97);
    insert(&head, 1);
    
    printf("\nLinked List before Sorting :");
    printList(head);
 
    quick_sort(head, last_node(head));
    printf("\nLinked List after Sorting :");
    printList(head);
    
    return 0;
}
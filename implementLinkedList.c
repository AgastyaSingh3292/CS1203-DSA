//Implement a Linked List

#include <stdio.h>
#include <stdlib.h>

struct node { //structure for node in linked list
    int data;
    struct node * next;
};

int main()
{
    struct node * head; //initializing nodes in the linked list
    struct node * second;
    struct node * third;
    struct node * fourth;
    
    head = (struct node *)malloc(sizeof(struct node)); //giving memory to nodes
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    
    head -> data = 13; //providing data to node
    head -> next = second; //providing address of next node
    
    second -> data = 52;
    second -> next = third;
    
    third -> data = 4;
    third -> next = fourth;
    
    fourth -> data = 61;
    fourth -> next = NULL;
    
    printList(head); //calling function to print data in nodes
    
    return 0;
}

void printList(struct node * ptr) //function to print value in  nodes
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}
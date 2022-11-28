#include <stdio.h>
#include <stdlib.h>

struct node { //structure for creating nodes
   int data;
   struct node* next;
};

struct node* head = NULL; //creating head node
struct node* nodeSort = NULL; //creating node to store sorted element

void push(int item) //function to push items in linked list
{
   struct node* newNode; //creating node to store new elements
   newNode = (struct node*)malloc(sizeof(struct node)); //allocating memory
   newNode -> data = item;
   newNode -> next = head;
   head = newNode;
}
void insertSort(struct node* newNode) 
{
   if (nodeSort == NULL || nodeSort -> data >= newNode -> data) 
   {
       newNode -> next = nodeSort;
       nodeSort = newNode;
   }
   else 
   {
       struct node* current = nodeSort;
       while (current -> next != NULL && current->next->data < newNode->data) 
       {
           current = current -> next;
       }
       newNode -> next = current -> next;
       current -> next = newNode;
   }
}
void insertionsort() //function to sort linked list
{
   struct node* current = head;
   while (current != NULL)
   {
       struct node* next = current -> next;
       insertSort(current);
       current = next;
   }
   head = nodeSort;
}
void printList(struct node* head) //function to print linked list
{
   while (head != NULL)
   {
       printf("%d -> ", head -> data);
       head = head -> next;
   }
   printf("NULL");
}
int main()
{
    push(14); //pushing elements in node
    push(65);
    push(81);
    push(5);
    push(73);
    push(31);
    
    printf("Sorted Linked List:\n");
    insertionsort(head); //calling function to sort linked list
    printList(head); //printing the sorted linked list
    
    return 0;
}
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

void selectionSort(struct node * head)//function to implement Selection sort on linked list
{
    struct node * temp = head;
  
    while (temp) 
    {
        struct node * min = temp;
        struct node * r = temp->next;

        while (r) 
        {
            if (min->data > r->data)
                min = r;
  
            r = r->next;
        }
  
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
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
    selectionSort(head); //calling function to sort linked list
    printList(head); //printing the sorted linked list
    
    return 0;
}
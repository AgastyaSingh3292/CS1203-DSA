#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

struct node * reverse (struct node * head, int k)
{
	if (!head)
	{
		return NULL;
    }
	
	struct node* current = head;
	struct node* next = NULL;
	struct node* prev = NULL;
	int count = 0;

	while (current != NULL && count < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	
	if (next != NULL)
	head->next = reverse(next, k);

	return prev;
}


void push(struct node** head_ref, int new_data)
{

	struct node* new_node;
	new_node = (struct node*) malloc(sizeof(struct node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(struct node * item)
{
	while (item != NULL)
	{
		printf("%d ", item->data);
		item = item->next;
	}
}

int main(void)
{

	struct Node* head = NULL;

	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);		

	head = reverse(head, 3);

	printf("\nReversed Linked list \n");
	printList(head);

	return(0);
}

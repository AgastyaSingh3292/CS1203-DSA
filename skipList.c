#include <stdio.h>
#include <stdlib.h>

// Define a node in the skip list
struct node
{
    int value;
    struct node *next;
    struct node *skip;
};

// Create a new node with the given value
struct node * create_node(int value) 
{
    struct node * new_node;
    new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->skip = NULL;

    return new_node;
}

// Insert a new node with the given value into the skip list
void insert(struct node *head, int value) 
{
    // Create the new node
    struct node *new_node = create_node(value);

    // Find the position to insert the new node
    struct node *curr = head;
    while (curr->next != NULL && curr->next->value < value) 
    {
        curr = curr->next;
    }

    // Insert the new node
    new_node->next = curr->next;
    curr->next = new_node;

    // Set the skip pointer
    if (curr->skip != NULL) 
    {
    new_node->skip = curr->skip->next;
    }
}

// Print the skip list
void print_list(struct node *head) 
{
    struct node *curr = head;
    while (curr != NULL) 
    {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    // Create the head node
    struct node *head = create_node(0);
    
    // Insert some nodes into the skip list
    insert(head, 5);
    insert(head, 10);
    insert(head, 7);
    insert(head, 3);
    
    // Print the skip list
    print_list(head);
    
    return 0;
}





#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct node {
  int data;
  struct node* next;
};

// Function to print the first half of a linked list
void print_first_half(struct node* head) {
  struct node* slow = head;
  struct node* fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  // At this point, slow is pointing to the middle element of the list
  // We can just iterate through the first half of the list and print the elements
  struct node* current = head;
  while (current != slow) {
    printf("%d ", current->data);
    current = current->next;
  }
}

// Function to create a new node and insert it at the end of the linked list
void insert_node(struct node** head, int data) {
  // Allocate memory for the new node
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  // Check if the linked list is empty
  if (*head == NULL) {
    *head = new_node;
    return;
  }

  // Find the last node in the linked list
  struct node* current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  // Insert the new node at the end of the linked list
  current->next = new_node;
}

int main() {
  // Create a linked list with some elements
  struct node* head = NULL;
  insert_node(&head, 1);
  insert_node(&head, 2);
  insert_node(&head, 3);
  insert_node(&head, 4);
  insert_node(&head, 5);

  // Print the first half of the linked list
  print_first_half(head);

  return 0;
}

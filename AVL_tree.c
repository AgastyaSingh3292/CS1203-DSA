#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
};

int max(int a, int b);

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) 
{
  return (a>b)?a:b;
}

// Create a node
struct node *newNode(int key) 
{
      struct node *new_node;
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->key = key;
      new_node->left = NULL;
      new_node->right = NULL;
      new_node->height = 1;
      return (new_node);
}

// Right rotate
struct node *rightRotate(struct node *y) 
{
  struct node *x = y->left;
  struct node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct node *leftRotate(struct node *x) {
  struct node *y = x->right;
  struct node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct node *N) 
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert node
struct node *insertNode(struct node *item, int key) 
{
  if (item == NULL)
  {
    return (newNode(key));
  }

  if (key < item->key)
  {
    item->left = insertNode(item->left, key);
  }
  else if (key > item->key)
  {
    item->right = insertNode(item->right, key);
  }
  else
  {
    return item;
  }
  
  item->height = 1 + max(height(item->left),
               height(item->right));

  int balance = getBalance(item);
  
  if (balance > 1 && key < item->left->key)
    return rightRotate(item);

  if (balance < -1 && key > item->right->key)
    return leftRotate(item);

  if (balance > 1 && key > item->left->key) {
    item->left = leftRotate(item->left);
    return rightRotate(item);
  }

  if (balance < -1 && key < item->right->key) {
    item->right = rightRotate(item->right);
    return leftRotate(item);
  }

  return item;
}

struct node *minValueNode(struct node *item) {
  struct node * current = item;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct node *deleteNode(struct node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreOrder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

int main() {
  struct node *root = NULL;

  root = insertNode(root, 11);
  root = insertNode(root, 143);
  root = insertNode(root, 34);
  root = insertNode(root, 87);
  root = insertNode(root, 12);
  root = insertNode(root, 38);
  root = insertNode(root, 29);

  printPreOrder(root);
  
  return 0;
}
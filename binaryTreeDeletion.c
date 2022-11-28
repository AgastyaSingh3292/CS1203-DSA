//function to delete root node of Binary tree
#include<stdio.h>
#include<stdlib.h>
 
struct node{ //defining node for binary tree
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* createNode(int data)
{
    struct node * new_node;
    new_node = (struct node *) malloc(sizeof(struct node)); // Allocating memory to node
    new_node -> data = data; 
    new_node -> left = NULL; 
    new_node -> right = NULL; 
    return new_node; 
}
 
void traversal(struct  node * root)//function to traverse binary tree inorder
{
    if(root != NULL)
    {
        traversal(root -> left);
        printf("%d --> ", root -> data);
        traversal(root -> right);
    }
}

void insertNode(struct node * root, int item) //function to insert node
{
    struct node * prev = NULL;
    
    while(root != NULL)
    {
        prev = root;
        if(item < root->data)
        {
            root = root -> left;
        }
        else
        {
            root = root -> right;
        }
    }
    
    struct node * new_node = createNode(item);
     
    if(item < prev->data)
    {
        prev -> left = new_node;
    }
    else{
        prev -> right = new_node;
    }
}

struct node *pred_node(struct node * root)
{
    root = root -> left;
    while (root -> right != NULL)
    {
        root = root -> right;
    }
    return root;
}

struct node * deleteNode(struct node * root, int key){

    struct node * pre_node;
    if (root == NULL)
    {
        return NULL;
    }
    if (root -> left == NULL && root -> right == NULL)
    {
        free(root);
        return NULL;
    }

    //finding the node to be deleted
    if (key < root -> data)
    {
        root-> left = deleteNode(root -> left, key);
    }
    else if (key > root -> data)
    {
        root-> right = deleteNode(root -> right, key);
    }

    else{
        pre_node = pred_node(root);
        root -> data = pre_node -> data;
        root -> left = deleteNode(root -> left, pre_node -> data);
    }
    return root;
}
 
int main(){
     
    struct node *n = createNode(23);//creating node for binary tree
    struct node *n1 = createNode(45);
    struct node *n2 = createNode(64);
    struct node *n3 = createNode(12);
    struct node *n4 = createNode(4);
    
    n->left = n1;//assigning nodes to binary tree
    n->right = n2;
    n1->left = n3;
    n1->right = n4;
    
    int key = 0;

    printf("Inorder Traversal of Binary Tree: \n");
    traversal(n);//binary tree before deletion
    deleteNode(n, key);
    printf("\nBinary Tree after deletion of root node: \n");
    traversal(n);//binary tree after deletion
    
    return 0;
}

//Binary Tree in Level Order

#include <stdio.h>
#include <stdlib.h>

struct node //structure to create nodes
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * newNode(int item) //function to creates new nodes in tree
{
	struct node * new_node;
	new_node = (struct node *)malloc(sizeof(struct node));//allocating memory to node
	new_node -> data = item;
	new_node -> left = NULL;
	new_node -> right = NULL;
	
	return new_node; //returning new node
}

struct node * insertNode(int arr[], int i, int n)//func to insert node in tree
{
	struct node * root = NULL; 
	if (i < n)
	{
		root = newNode(arr[i]);

		root -> left = insertNode(arr,2*i+1,n);
		root -> right = insertNode(arr,2*i+2,n);
	}
	return root;
}

void traversal(struct node * root) //function to traverse binary tree in InOrder
{
	if (root != NULL)
	{
		traversal(root -> left);
		printf("%d --> ", root -> data);
		traversal(root -> right);
	}
}

int main()
{
	int arr[] = {11, 45, 67, 34, 9, 26};//array to convert to binary tree
	int len = sizeof(arr)/sizeof(arr[0]);//size of array
	
	struct node * root = insertNode(arr, 0, len);
	
	printf("In-Order Traversal of Binary Tree - \n");
	traversal(root);//printing binary tree
	
	return 0;
}

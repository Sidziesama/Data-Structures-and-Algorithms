#include <stdio.h>
#include <stdlib.h>

// Binary Search Trees

/** Basic Theory and Operations
 * The one pre-requisite of Binary Search is that the array should be in a sorted order.
 * In most cases, a BST cannot be unique.
 * Binary Search tree operations :
 * 1) Insertion
 * 2) Search
 * 3) Deletion
 * 4) Traversal :
 * -Inorder, pre-order and post-order
 *
 */

// Define Node Structure
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

} Node;

// Create New Node Function
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Function to Insert new node into BST
Node *insert(Node *root, int data)
{
  if (root == NULL)
  {
    return createNode(data);
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
  }
  else if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  return root;
}

// Find smallest value in the tree
Node *findMin(Node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

// Function to delete a node from BST
Node *delete(Node *root, int data)
{
  if (root == NULL)
  {
    printf("Here");
    return root;
  }
  else if (data < root->data)
  {
    root->left = delete (root->left, data);
  }
  else if (data > root->data)
  {
    root->right = delete (root->right, data);
  }
  else
  {
    // Node with only one child or no child
    if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    Node *temp = findMin(root->right);
    root->data = temp->data;
    root->right = delete (root->right, temp->data);
  }
  return root;
}

// Function to search for a key in the BST
Node *search(Node *root, int key)
{
  if (root == NULL || root->data == key)
  {
    return root;
  }
  if (key < root->data)
  {
    return search(root->left, key);
  }
  return search(root->right, key);
}

// Function to perform inorder traversal of the BST (left -Root- Right)
void inorderTraversal(Node *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

// Function for preorder traversal of the BST (Root-Left-Right)
void preorderTraversal(Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

// Function for postorder traversal of the BST (Left-Right-Root)
void postorderTraversal(Node *root)
{
  if (root != NULL)
  {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}

void main()
{
  Node *root = NULL;
  int array[] = {85, 70, 100, 20, 40, 90, 105, 10};
  // int array [] ={8,7, 9, 5, 4, 11, 10,14,4,1};

  int size_of_array = sizeof(array) / sizeof(array[0]);

  // Insert elements into the BST
  printf("INSERTION:\n");
  for (int i = 0; i < size_of_array; i++)
  {
    root = insert(root, array[i]);
    printf("Element %d inserted into BST\n", array[i]);
  }

  printf("TRAVERSAL : \n");

  // Inorder traversal of the BST (Sorted order)
  printf("Inorder traversal of the BST: ");
  inorderTraversal(root);
  printf("\n");

  // Preorder traversal of the BST
  printf("Preorder traversal of the BST: ");
  preorderTraversal(root);
  printf("\n");

  // Search for an element in the BST
  int key = 20;
  printf("SEARCH OPERATION : \n Searching for element %d in BST...\n", key);
  Node *result = search(root, key);
  if (result != NULL)
  {
    printf("%d found in the BST.\n", key);
  }
  else
  {
    printf("%d not found in the BST.\n", key);
  }

  // Delete an element from the BST
  int deleteKey = 100;
  printf("DELETE OPERATION : \n Deleting element %d from BST ...\n", deleteKey);
  // Search if element exists
  Node *key_search = search(root, deleteKey);

  if (key_search != NULL)
  {
    root = delete (root, deleteKey);
    if (root != NULL)
    {
      printf("%d successfully deleted from the BST.\n", deleteKey);
    }
    else
      printf("Delete Unsuccessful");
  }
  else
  {
    printf("Cannot delete %d. Not found in the BST.\n", deleteKey);
  }

  // Postorder traversal of the BST
  printf("Postorder traversal of the BST: ");
  postorderTraversal(root);
  printf("\n");
}


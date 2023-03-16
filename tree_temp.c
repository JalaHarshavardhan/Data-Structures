// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorder(struct node* root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ->", root->data);
  inorder(root->right);
}

// preorder traversal
void preorder(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->data);
  preorder(root->left);
  preorder(root->right);
}

// postorder traversal
void postorder(struct node* root) {
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ->", root->data);
}

// Create a new Node
struct node* createnode(value) {
  struct node* newnode = malloc(sizeof(struct node));
  newnode->data = value;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createnode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createnode(value);
  return root->right;
}

int main() {
  struct node* root = createnode(1);
  insertLeft(root, 12);
  insertRight(root, 9);

  insertLeft(root->left, 5);
  insertRight(root->left, 6);

  printf("Inorder traversal \n");
  inorder(root);

  printf("\nPreorder traversal \n");
  preorder(root);

  printf("\nPostorder traversal \n");
  postorder(root);
}
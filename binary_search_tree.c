#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *create_node(int);
void insert(int);
void inorder(struct node *);
void postorder(struct node *);
void preorder(struct node *);
int get_data();
int main()
{
    int userChoice;
    int userActive = 'Y';
    int data;
    struct node* result = NULL;
 
        printf("\n\n------- Binary Search Tree ------\n");
        printf("\n1. Insert");
        printf("\n2. Inorder ");
        printf("\n3. Post Order ");
        printf("\n4. Pre Oder ");
        printf("\n5. Exit");
    while (userActive == 'Y' || userActive == 'y')
    {
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &userChoice);
        printf("\n");
 
        switch(userChoice)
        {
            case 1: data = get_data();
                    insert(data);
                    break;
            case 2: inorder(root);
                    break;
            case 3: postorder(root);
                    break;
            case 4: preorder(root);
                    break;
            case 5: exit(0);
                    break;
            default: printf("\n\tInvalid Choice\n");
                     break;
        }
    }
    return 0;
}

struct node *create_node(int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(int data)
{
    struct node *new_node;
    new_node = create_node(data);
    if (new_node != NULL)
    {
        // if the root is empty then make a new node as the root node
        if (root == NULL)
        {
            root = new_node;
            printf("\n* node having data %d was inserted\n", data);
            return;
        }
 
        struct node *temp = root;
        struct node *prev = NULL;
 
        // traverse through the BST to get the correct position for insertion
        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
 
        // found the last node where the new node should insert
        if (data > prev->data)
        {
            prev->right = new_node;
        }
        else
        {
            prev->left = new_node;
        }
 
        printf("\n* node having data %d was inserted\n", data);
    }
}
 
// inorder traversal of the BST
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",  root->data);
    inorder(root->right);
}
 
// preorder traversal of the BST
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
 
// postorder travsersal of the BST
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
 
// getting data from the user
int get_data()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}
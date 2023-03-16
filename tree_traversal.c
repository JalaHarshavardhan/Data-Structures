#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data (-1 for no node):");
    scanf("%d", &x);
    if(x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter the left child of %d: ", x);
    newnode->left = create();
    printf("Enter the right child of %d: ", x);
    newnode->right = create();
    return newnode;
}
void preorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
}
void inorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}
void main()
{
    struct node *root;
    int choice = 0;
    while(choice != 5)
    {
        printf("\n1.Create node\n2.Pre Order\n3.Post Order\n4.In Order\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: root = create();
                    break;
            case 2: preorder(root);
                    break;
            case 3: postorder(root);
                    break;
            case 4: inorder(root);
                    break;
            case 5: exit(0);
                    break;
            default:printf("Enter valid choice!!");
        }
    }
    
    
    
}
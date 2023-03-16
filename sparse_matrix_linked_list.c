// sparse matrix linked list representation
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int row, column, value;
    struct node *next;
};
struct node *head=NULL, *temp;
void main()
{
    // read sparse matrix
    int i, j, rows, columns;
    // int sparse_matrix[100][100];    //---->for turbo c
    printf("\nEnter the credentials of sparse matrix;");
    printf("\nRows:");
    scanf("%d", &rows);
    printf("\nRows:");
    scanf("%d", &columns);
    int sparse_matrix[rows][columns];
    printf("\nEnter the elements of the sparse matrix:\n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
    printf("\nThe sparse matrix:\n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            printf("%d\t", sparse_matrix[i][j]);
        }
        printf("\n");
    }
    // finalize matrix
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            if(sparse_matrix[i][j]!=0)
            {
                struct node *newnode, *temp;
                newnode = (struct node *)malloc(sizeof(struct node));
                newnode->row = i;
                newnode->column = j;
                newnode->value = sparse_matrix[i][j];
                if(head == NULL)
                {
                    head = newnode;
                    newnode->next = NULL;
                }
                else
                {
                    temp = head;
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newnode;
                    newnode->next =NULL;
                }
            }
        }
    }
    // display finalized matrix
    printf("\nThe finalized matrix:\n");
    if(head == NULL)
    {
        printf("\nThere is nothing to print\n");
    }
    else
    {
        temp = head;
        printf("Rows\tColumns\t   Value\n");
        while(temp != NULL)
        {
            printf("  %d\t   %d\t     %d\n", temp->row, temp->column, temp->value);
            temp = temp->next;
        }
    }
}
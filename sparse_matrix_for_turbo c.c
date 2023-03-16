// sparse matrix array representation
#include<stdio.h>
void main()
{
    int rows, columns;
    int i, j, k=0;
    int sparse_matrix[100][100]; 
    printf("\nEnter sparse matrix credentials:");
    printf("\nRows:");
    scanf("%d", &rows);
    printf("\nColumns:");
    scanf("%d", &columns);
    printf("Enter the elements of the matrix:");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
    printf("\nThe sparse matrix :\n");

    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            printf("%d\t", sparse_matrix[i][j]);
        }
        printf("\n");
    }

    // calcualting size of new matrix
    int size = 0;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            if(sparse_matrix[i][j] != 0)
            {
                size++;
            }
        }
    }

    // final matrix computation
    int matrix[3][size];
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            if(sparse_matrix[i][j] != 0)
            {
                matrix[0][k] = i;
                matrix[1][k] = j;
                matrix[2][k] = sparse_matrix[i][j];
                k++;
            }
        }
    }

    // printing final matrix
    printf("\nThe final matrix is:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}                                
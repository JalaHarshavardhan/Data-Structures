// sparse matrix array representation
#include<stdio.h>
void main()
{
    int rows, columns;
    int k=0;
    // int matrix[3][size];         //--->for turbo c
    // int sparse_matrix[100][100]; //--->for turbo c
    printf("\nEnter sparse matrix credentials:");
    printf("\nRows:");
    scanf("%d", &rows);
    printf("\nColumns:");
    scanf("%d", &columns);
    printf("Enter the elements of the matrix:");
    int sparse_matrix[rows][columns];
    // int sparse_matrix[100][100]; 
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            scanf("%d", &sparse_matrix[i][j]);
        }
    }
    printf("\nThe sparse matrix :\n");

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            printf("%d\t", sparse_matrix[i][j]);
        }
        printf("\n");
    }

    // calcualting size of new matrix
    int size = 0;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(sparse_matrix[i][j] != 0)
            {
                size++;
            }
        }
    }

    // final matrix computation
    int matrix[3][size];
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
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
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<size; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}                                
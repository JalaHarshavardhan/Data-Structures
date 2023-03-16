//  matrix multiplication
#include<stdio.h>
void main()
{
    int a[10][10],b[10][10],c[10][10];
    int i,j,m,n,x,y,k,sum;
    printf("Enter the no of rows and columns of matrix A:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of matrix A:\n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the no of rows and columns of matrix B:\n");
    scanf("%d%d",&x,&y);
    printf("Enter the elements of matrix B:\n");
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("Matrix A:\n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    printf("Multiplication of matrix A and matrix B:\n");
    if(n!=x)
    {
        printf("Matrix addition is not possible!!");
    }
    else
    {
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=y;j++)
            {
                sum=0;
                for(k=1;k<=x;k++)
                {
                    sum+=a[i][k]*b[k][j];
                }
                c[i][j]=sum;
            }
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=y;j++)
            {
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
}
// matrix addition
#include<stdio.h>
void main()
{
    int a[10][10],b[10][10],c[10][10];
    int i,j,m,n,x,y;
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
    printf("Sum of matrix A and matrix B:\n");
    if(m==x&&n==y)
    {
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                c[i][j]=a[i][j]+b[i][j];
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
    else
    printf("Matrix addition is not possible!!");
}
// matrix trace
#include<stdio.h>
void main()
{
    int a[10][10];
    int i,j,m,n,trace=0;
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
    printf("Matrix A:\n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                trace+=a[i][j];
            }
        }
    }
    printf("Trace of matrix A is %d",trace);
}

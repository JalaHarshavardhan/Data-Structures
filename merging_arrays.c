// merge array
#include<stdio.h>
#define N 5
#define M 6
void main()
{
    int a[N], b[M], c[N+M], i, index=0;
    printf("Enter the elements for first array:\n");
    for(i=0;i<N;i++)
    scanf("%d",&a[i]);

    printf("Enter the elements for second array:\n");
    for(i=0;i<M;i++)
    scanf("%d",&b[i]);

    printf("Merging of a[%d] and b[%d]:\n",N,M);
    for(i=0;i<N;i++)
    c[index++]=a[i];
    for(i=0;i<M;i++)
    c[index++]=b[i];

    printf("Elements of c[%d] are:\n",(M+N));
    for(i=0;i<(M+N);i++)
    printf("%d  ",c[i]);
}
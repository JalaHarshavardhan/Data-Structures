// selection sort
#include<stdio.h>
void main()
{
    int i,j,n,temp,min;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements of the array:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nArray before sorting:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    // selection sort
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
    printf("\nArray after sorting:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
// insertion sort
#include<stdio.h>
void main()
{
    int i,j,n,temp;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements of the array:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nArray before sorting:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    // Insertion sort
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while ((j>=0) && (a[j]>temp))
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("\nArray after sorting:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
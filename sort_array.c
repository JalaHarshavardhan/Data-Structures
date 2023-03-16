// sort array
#include<stdio.h>
void main()
{
    int i,j,temp=0,n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements of the array:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray before sorting:");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            
        }
    }
    printf("\nArray after sorting:");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
}
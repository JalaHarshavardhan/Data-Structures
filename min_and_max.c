// min and max of array
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
    //sorting
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
    printf("\nArray in ascending order:");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nThe min value of array is %d",a[1]);
    printf("\nThe max value of array is %d",a[n]);
}
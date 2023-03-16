// bubble sort
#include<stdio.h>
void main()
{
    int i,j,n,temp,hm;
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
    //Bubble sort:
    for(i=1;i<=n-1;i++)
    {
        hm=0;
        for(j=1;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                hm=1;
            }
        }
        if(hm==0)
        {
            break;
        }
    }
    printf("\nArray after sorting:");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
        
}
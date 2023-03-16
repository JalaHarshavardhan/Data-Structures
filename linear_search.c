// linear search
#include<stdio.h>
void main()
{
    int key=43,found=0,i,n;
    // int key
    int a[5]={2,4,65,43,22};
    // printf("Enter the size of the array:");
    // scanf("%d",&n);
    // int a[n];
    // printf("\nEnter the elements of the array:");
    // for(i=0;i<n;i++)
    // scanf("%d",&a[i]);
    // printf("\nkey:");
    // scanf("%d",&key);
    for(i=1;i<=5;i++)
    {
        if(a[i]==key)
        {
            printf("The element is found at %d index",i);
            printf("\nThe element is found at %d position",i+1);
            found=1;
            break;   
        }
    }
    if(found==0)
    printf("The %d element is not found",key);
}
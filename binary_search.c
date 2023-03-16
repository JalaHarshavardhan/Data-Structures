// binary search
#include<stdio.h>
void main()
{
    int a[100],i,n,mid,low,high,key;
    printf("\nEnter n value:");
    scanf("%d",&n);
    printf("\nEnter %d array elements:",n);
    for(i=1;i<=n;i++)        
    scanf("%d",&a[i]);
    low=1;
    high=n;
    mid=(low+high)/2;
    printf("\nEnter the key value:");
    scanf("%d",&key);
    while ((low<=high)&&(key!=a[mid]))
    {
        if(key<a[mid])
            high=mid-1;
        else
        {
            low=mid+1;
            mid=((low+high)/2);
        }
            
    }
    if(low>high)
    printf("\nKey element is not found");
    else
    printf("\nkey element is found at %d position",mid);
}
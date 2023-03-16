// merge sort
#include<stdio.h>
void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int b[20];
    i = low;
    j = mid+1;
    k = low;
    while(i<=mid && j<=high)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=high)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for(k=low; k<=high; k++)
    {
        a[k] = b[k];
    }
}

void mergesort(int a[], int low, int high)
{
    if(low<high)
    {
        int mid;
        mid = (low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}
void print(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
}
void main()
{
    // int a[20], i;
    int n, low, high, mid;
    printf("Total elements in the array:");
    scanf("%d", &n);
    int a[n], i;
    printf("\nEnter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting:\n");
    print(a, n);
    low = 0;
    high = n;
    mergesort(a, low, high);
    printf("\nAfter sorting:\n");
    print(a, n);
}


    

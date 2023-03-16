// quick sort
#include<stdio.h>
int partition(int a[], int low, int high)
{
    int pivot, start, end, m;
    pivot = a[low];
    start = low;
    end = high;
    while(start<end)
    {
        while(a[start] <= pivot)
        {
            start++;
        }
        while(a[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            int h;
            h = a[start];
            a[start] = a[end];
            a[end] = h;
        }
    }
    m = a[low];
    a[low] = a[end];
    a[end] = m;
    return end;
}

void Quicksort(int a[], int low, int high)
{
    if(low<high)
    {
        int loc;
        loc = partition(a, low, high);
        Quicksort(a, low, loc-1);
        Quicksort(a, loc+1, high);
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
    int n, low, high;
    printf("Total elements in the array:");
    scanf("%d", &n);
    low = 0;
    high = n;
    int a[n], i;
    printf("\nEnter the elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting:\n");
    print(a, n);
    Quicksort(a, low, high);
    printf("\nAfter sorting:\n");
    print(a, n);
}
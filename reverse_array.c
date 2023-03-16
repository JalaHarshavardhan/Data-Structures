// reverse array
#include<stdio.h>
void reverse_array(int a[], int start, int end)
{
    int temp;
    while(start<end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

void print_array(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
}
void main()
{
    int n, i;
    printf("Total elements in the array:");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray before reversing:\n");
    print_array(a, n);
    reverse_array(a, 0, n-1);
    printf("\nArray after reversing:\n");
    print_array(a, n);
}
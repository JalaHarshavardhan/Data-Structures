#include<stdio.h>
int stack[100];
int top=0;
void main()
{
    // int a[5]={10, 20, 30, 40, 50};
    int n, i, x, a[100];
    printf("Total no of elements in Array:");
    scanf("%d", &n);
    printf("\nEnter %d elements:\n", n);
    // read array from the user
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    // push the array elements into the stack
    for(i=0; i<n; i++)
    {
        top++;
        stack[top] = a[i];
    }
    printf("Array before reversing:\n ");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i])    ;
    }
    printf("\nArray after reversing:\n ");
    // pop and print the array elements from the stack
    for(i=0; i<n; i++)
    {
        x = stack[top];
        top--;
        printf("%d\t", x);
    }
}
// stack (array implementation)
#include<stdio.h>
#include<stdlib.h>
int stack[20];
int top = 0;
int n;
void push();
int pop();
void peek();
void display();
void reverse_array();

void main()
{
    int choice = 0;
    printf("\nEnter the number of elements in the stack:");
    scanf("%d", &n);
    printf("\n----------Stack Operations Using Array----------");
    printf("\n------------------------------------------------");
    while(choice != 6)
    {
        printf("\nChoose one option from the following");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Reverse array\n6.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                push();
                break;
            case 2: 
                pop();
                break;
            case 3:
                peek();
                break;
            case 4: 
                display();
                break;
			case 5:
				reverse_array();
				break;
            case 6: 
                exit(0);
                break;
            default:
                printf("\nEnter valid choice!!");
        }
    }
}
void push()
{
    int ele;
    if(top == n)
    {
        printf("\nStack is overflow");
    }
    else
    {
        printf("\nEnter the element you want to push into the stack:");
        scanf("%d", &ele);
        top++;
        stack[top] = ele;
        printf("\n%d pushed into the stack", ele);
    }
}
int pop()
{
    int item;
    if(top == 0)
    {
        printf("\nUnderflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf("\nPopped item is %d", item);
    }
	return item;
}
void peek()
{
    if(top == 0)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("The top most element is %d", stack[top]);
    }
}
void display()
{
    int i;
    for(i = top; i>0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if(top == 0)
    {
        printf("\nStack is empty");
    }
}
void reverse_array()
{
	int i;
	int a[n];
	for(i=0; i<n; i++)
	{
		push(a[i]);
	}
	for(i=0; i<n; i++)
	{
		a[i]=pop();
	}
    printf("\nArray after reversing:\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", a[i]);
	}
}
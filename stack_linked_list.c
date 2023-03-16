// stack (linked list implementation)
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *head;
void push();
void pop();
void display();
void main()
{
    int choice=0;
    printf("\n-------Stack Operations Using Linked List-------");
    printf("\n------------------------------------------------");
    while(choice != 4)
    {
        printf("\nChoose one option from the following");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break; 
            default:
                printf("\nEnter valid choice!!");
        }
    }
}
void push()
{
    struct stack *newstack, *temp;
    newstack = (struct stack *)malloc(sizeof(struct stack));
    printf("\nEnter the data to push into the stack:");
    scanf("%d", &newstack->data);
    if(head == NULL)
    {
        head = newstack;
        newstack->next = NULL;
    }
    else
    {
        newstack->next = head;
        head = newstack;
    }
    printf("%d pushed", newstack->data);
}
void pop()
{
    struct stack *temp;
    if(head == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        printf("\nItem popped");
    }
}
void display()
{
   struct stack *temp;
   temp = head;
   if(head == NULL)
   {
    printf("\nStack is empty!!");
   }
   else
   {
        printf("Printing Stack elements \n"); 
        while(temp!=NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
   }
}
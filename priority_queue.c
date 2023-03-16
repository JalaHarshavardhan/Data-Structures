#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void insert_by_priority();
void delete_by_priority();
void check(int);
void display_pqueue();
int pri_que[MAX];
int front=-1, rear=-1;
void main()
{
    int choice = 0;
	printf("-------------------------------------------------------");
	printf("\n------Priority Queue Operations Using Arrays------");
	printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    while (choice != 4)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: 
            insert_by_priority();
            break;
        case 2:
            delete_by_priority();
            break;
        case 3: 
            display_pqueue();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}

void insert_by_priority()
{
    int ele;
    printf("\nEnter value to be inserted : ");
    scanf("%d", &ele);
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = ele;
        return;
    }    
    else{
        check(ele);
        rear++;
    }
}

void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}

void delete_by_priority()
{
    int ele, i;
    printf("\nEnter value to delete : ");
    scanf("%d",&ele);
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    for (i = 0; i <= rear; i++)
    {
        if (ele == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }
        // pri_que[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", ele);
}

void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue is:\n");
    for (; front <= rear; front++)
    {
        printf("%d\n", pri_que[front]);
    }
    front = 0;
}
#include<stdio.h>
#include<stdlib.h>
#define size 5
int Q[size];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void display();
void main()
{
	int choice = 0;
	printf("-----------------------------------------");
	printf("\n------Queue Operations Using Arrays------");
	printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
	while(choice != 4)
	{
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: enqueue();
					break;
			case 2: dequeue();
			        break;
			case 3: display();
					break;
			case 4: exit(0);
					break;
			default:
				printf("\nEnter valid choice");
		}
	}
}
void enqueue()
{
	int ele;
	printf("Enter the element to insert into the queue:");
	scanf("%d", &ele);
	if(rear == size-1)
	{
		printf("\nOverflow");
	}
	if(front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		rear++;
	}
	Q[rear] = ele;
	printf("%d inserted", ele);
}
void dequeue()
{
    int ele;
    if(front == -1 || front>rear)
    {
        printf("\nOverflow");
    }
    else
    {
        ele = Q[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        printf("%d deleted", ele);
    }
    
}

void display()
{
    int i;
    if(rear == -1)
    {
        printf("\nQueue is empty!!");
    }
    else
    {
        printf("Queue:\n");
        for(i=front; i<=rear; i++)
        {
            printf("%d\n", Q[i]);
        }
    }
}

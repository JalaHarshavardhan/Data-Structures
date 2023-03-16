#include<stdio.h>
#include<stdlib.h>
#define N 5
int front=-1, rear=-1;
int Q[N];
void enqueue();
void dequeue();
void display();
void peek();
void main()
{
    int choice = 0;
	printf("--------------------------------------------------");
	printf("\n------Circular Queue Operations Using Arrays------");
	printf("\n1.Insert\n2.Delete\n3.Peek element\n4.Display\n5.Exit");
	while(choice != 5)
	{

		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: enqueue();
					break;
			case 2: dequeue();
			        break;
            case 3: peek();
                    break;
			case 4: display();
					break;
			case 5: exit(0);
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
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        Q[rear] = ele;
        printf("%d inserted", ele);
    }
    else if(((rear+1)%N)==front)
    {
        printf("\nOverflow");
    }
    else
    {
        rear = ((rear+1)%N);
        Q[rear] = ele;
        printf("%d inserted", ele);
    }
}
void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("\n%d deleted", Q[front]);
        front = ((front+1)%N);
    }
}
void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("Queue is:\n");
        while(i != rear)
        {
            printf("%d\n", Q[i]);
            i = (i+1)%N;
        }
        printf("%d", Q[i]);
    }   
}
void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("%d", Q[front]);
    }
}
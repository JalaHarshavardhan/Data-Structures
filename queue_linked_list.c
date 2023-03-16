#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue();
void dequeue();
void display();
void main()
{
	int choice = 0;
	printf("------------------------------------------");
	printf("\n---Queue Operations Using Linked List---");
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
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to insert into the queue:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = NULL;
    }
    printf("%d enqueued", newnode->data);
}

void dequeue()
{
    struct node *temp;
    if(front == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        temp = front;
        printf("%d dequeued", front->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if(front == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("Queue:\n");
        temp = front;
        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

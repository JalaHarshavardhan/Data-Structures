#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL, *rear=NULL;
void enqueue();
void dequeue();
void display();
void peek();
void main()
{
    int choice = 0;
	printf("-------------------------------------------------------");
	printf("\n------Circular Queue Operations Using Linked List------");
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
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to insert:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if(rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("\nUnderflow");
    }
    else if(front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        while(temp->next != front)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
    printf("\n%d", temp->data);
}
void peek()
{
    if(front == NULL && rear == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nPeek element: %d", front->data);
    }
}
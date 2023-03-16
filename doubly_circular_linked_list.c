// double circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev, *next;
};
void front_insertion();
void display();
struct node *head;
int count=0;
void main()
{
	int choice = 0;
	while(choice != 3)
	{
		printf("\nChoose one option from the following list");
		printf("\n-----------------------------------------");
		printf("\n1.Front insertion\n2.display\n3.Exit");
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				front_insertion();
				break;
			case 2:
				display();
				break;
			case 3:
				exit(0);
				break;
			default:
			printf("\nEnter the valid choice");
		}
	}
}
void front_insertion()
{
	struct node *newnode, *temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the data:");
	scanf("%d", &newnode->data);
	if(head == NULL)
	{
		head = newnode;
		newnode->prev = head;
		newnode->next = head;
		count++;
		printf("\nNode inserted at front");
		printf("\nThe total elements are %d", count);
	}
	else
	{
		temp = head;
		while(temp->next != head)
		{
			temp = temp->next;
		}
		newnode->prev = temp;
		newnode->next = head;
		temp->next = newnode;
		head->next = newnode;
		head = newnode;
		count++;
		printf("\nNode inserted at front");
		printf("\nThe total elements are %d", count);
	}

}
void display()
{
   struct node *temp;
   temp = head;
   if(head == NULL)
   {
	 printf("\nList is empty!!");
   }
   else
   {
		while(temp->next!=head)
		{
			printf("%d-->", temp->data);
			temp = temp->next;
		}
   }
}
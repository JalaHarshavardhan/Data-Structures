// Circular linked list
#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next; 
};   
void front_insertion();
void rear_insertion();
void random_insertion();
void display();
void front_deletion();
void rear_deletion();
void delete_by_position();
void delete_by_value();
void search();
void sort();
struct node *head;
int count = 0;
void main()
{
    int choice = 0;  
    while(choice != 11)   
    {  
        printf("\nChoose one option from the following list ");  
        printf("\n------------------------------------------");  
        printf("\n1.Front insertion\n2.Rear insertion\n3.Random insertion\n4.Front deletion\n5.Rear deletion\n6.Delete by position\n7.Delete by value\n8.Search\n9.Sort\n10.Display\n11.Exit");  
        printf("\nEnter your choice:");         
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:
                front_insertion();
                break;
            case 2:  
                rear_insertion();     
                break;  
            case 3:
                random_insertion();
                break;
            case 4:
                front_deletion();
                break;
            case 5:
                rear_deletion();
                break;
            case 6:
                delete_by_position();
                break;
            case 7:
                delete_by_value();
                break;
            case 8:
                search();
                break;
            case 9:
                sort();
                break;
            case 10:
                display();
                break;
            case 11:  
                exit(0);  
                break;  
            default:  
            printf("Please enter valid choice..");
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
        newnode->next = head;
    }
    else
    {
        temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    count++;
    printf("\nNode inserted at front");
    printf("\nThe total elements are %d", count);
}
void rear_insertion()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d", &newnode->data);
    if(head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    printf("\nNode inserted at rear");
    count++;
    printf("\nThe total elements are %d", count);
}
void random_insertion()
{
    int i, position=0;
    struct node *newnonde, *temp, *temp1;
    if(head == NULL)
    {
        printf("\nList is empty!!");
    }
    else
    {
        printf("\nEnter the position:");
        scanf("%d", &position);
        if(position>count)
        {
            printf("Enter valid position");
        }
        else
        {
            if(position == 0)   
            {
                front_insertion();
            }
            else if(position == count)
            {
                rear_insertion();
            }
            else
            {
                newnonde = (struct node *)malloc(sizeof(struct node));
                printf("\nEnter the data:");
                scanf("%d", &newnonde->data);
                temp = head;
                for(i=0; i<position;i++)
                {
                    temp1 = temp;
                    temp = temp->next;
                    if(temp == NULL)
                    {
                        printf("\nCan't insert");
                    }
                }
                newnonde->next = temp;
                temp1->next = newnonde;
                printf("\nNode inserted at specified position");
                count++;
                printf("\nThe total elements are %d", count);
            }
        }
    }
}
void front_deletion()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nList is empty!!");
    }
    else if(head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nFront node deleted successfully");
        count--;
        printf("\nThe total elements are %d", count);
    }
    else
    {
        temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        printf("\nFront node deleted successfully");
        count--;
        printf("\nThe total elements are %d", count);
    }
}
void rear_deletion()
{
    struct node *temp, *temp1;
    if(head == NULL)
    {
        printf("\nList is empty!!");
    }
    else if(head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nRear node deleted successfully");
        count--;
        printf("\nThe total elements are %d", count);   
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = head;
        free(temp);
        count--;
        printf("\nRear node deleted successfully");   
        printf("\nThe total elements are %d", count);
    }
}
void delete_by_position()
{
    struct node *temp, *temp1;
    int i, position = 0;
    printf("\nEnter the position:");
    scanf("%d", &position);
    if(position>count)
    {
        printf("\nEnter valid position:");
    }
    else
    {
        if(position == 0)
        {
            front_deletion();
        }
        else if(position == count)
        {
            rear_deletion();
        }
        else
        {
            temp = head;
            for (i=0;i<position;i++)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = temp->next;
            free(temp);
            count--;
            printf("\nSpecified node deleted successfully");
            printf("\nThe total elements are %d", count);
        }
    }
}
void delete_by_value()
{
    struct node *temp, *temp1;
    int key;
    printf("\nEnter the key value:");
    scanf("%d", &key);
    temp = head;
    while(temp->data != key)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = temp->next;
    free(temp);
    printf("\nSpecified value delted successfully");
    count--;
    printf("\nThe total elements are %d", count);
}
void search()
{
    struct node *temp;
    int flag, i = 0, key;
    temp = head;
    if(head == NULL)
    {
        printf("\nList is empty!!");
    }
    else
    {
        printf("\nEnter the data you want to search:");
        scanf("%d", &key);
        if(head->data == key)  
        {  
            printf("item found at location %d",i+1);  
            flag=0;  
        } 
        else
        {
            while(temp->next != head)
            {
                if(temp->data == key)
                {
                    printf("\nKey found at location %d", i+1);
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                i++;
                temp = temp->next;
            }
            if(flag == 1)
            {
                printf("\nKey value not found");
            }
        }
    }
}
void sort()
{
    struct node *temp, *temp1;
    int h;
    temp = head;
    while (temp->next != head)
    {
        temp1 = temp->next;
        while (temp1 != head)
        {
            if(temp->data > temp1->data)
            {
                h = temp1->data;
                temp1->data = temp->data;
                temp->data = h;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    printf("\nElements are sorted");
}
void display()
{
    struct node *temp;
    temp = head;
    if(temp == NULL)
    {
        printf("\nList is empty!!");
    }
    else
    {
        while(temp->next != head)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("%d-->", temp->data);
    }
}
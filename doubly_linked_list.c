// Double linked list
#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next, *prev; 
};   
void front_insertion();
void rear_insertion(); 
void random_insertion();
void front_deletion();
void rear_deletion();
void delete_by_position();
void delete_by_value();
void search();
void display();
void sort();
struct node *head, *tail;
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
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d", &newnode->data);
    if(head == NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        printf("\nNode inserted");
        count++;
        printf("\nThe total elements are %d", count);
    }
    else
    {
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        printf("\nNode inserted at front");
        count++;
        printf("\nThe total elements are %d", count);
    }
}
void rear_insertion()
{
    struct node *newnode, *temp;
    // head = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("Enter the data:");
        scanf("%d", &newnode->data);
        if(head == NULL)
        {
            newnode->prev = NULL;
            newnode->next = NULL;                                    
            head = newnode;
            temp = newnode;
            printf("\nNode inserted at rear");
            count++;
            printf("\nThe total elements are %d", count);
        }
        else
        {
            temp = head;
            while(temp->next != NULL) //------------->space complexity of O(n) since for traversing
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = NULL;
            printf("\nNode inserted at rear");
            count++;
            printf("\nThe total elements are %d", count);
        }
    }

    // struct node *newnode;
    // newnode = (struct node *)malloc(sizeof(struct node));
    // printf("\nEnter the data:");
    // scanf("%d", &newnode->data);
    // if(head == NULL)
    // {
    //     newnode->prev = NULL;
    //     newnode->next = NULL;
    //     head = newnode;
    //     tail = newnode;
    //     printf("\nNode inserted");
    // }
    // else
    // {                          // space complexity of O(1)
    //     tail->next = newnode;
    //     newnode->prev = tail;
    //     newnode->next = NULL;
    //     tail = newnode;
    // }
    // printf("\nNode inserted at Rear");
}
void random_insertion()
{
    int i, position=0;
    struct node *newnode, *temp,*temp1;
    
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nEnter the position:");
        scanf("%d", &position);
        if(position > count)
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
                newnode = (struct node *)malloc(sizeof(struct node));
                printf("\nEnter the data:");
                scanf("%d", &newnode->data);
                temp = head;
                for(i=0;i<position;i++)
                {
                    temp1 = temp;
                    temp = temp->next;
                    if(temp == NULL)
                    {
                        printf("\nCannot insert");
                    }
                }
                newnode->prev = temp1;
                newnode->next = temp;
                temp1->next = newnode;
                temp->prev = newnode;
                count++;
                printf("\nNode inserted at random position");
                printf("\nThe total elements are %d", count);
            }
        }
    }  
}
void front_deletion()
{
    struct node *temp, *temp1;
    temp = head;
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp = head;
        head = temp->next;
        temp1 = temp;
        temp = temp->next;
        if(temp == NULL)
        {
            printf("\nList is empty!!");
        }
        else
        {
            temp1->next = NULL;
            temp->prev = NULL;
            free(temp1);
            printf("\nFront node deleted successfully");
            count--;
            printf("\nThe total elements are %d", count);   
        }
    }
}
void rear_deletion()
{
    struct node *temp, *temp1;
    
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    // else
    // {
    //     temp = tail;
    //     tail->prev->next = NULL;
    //     tail = tail->prev;
    //     free(temp);
    // }
    else if(head->next == NULL)
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
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        temp->prev = NULL;
        free(temp);
        printf("\nRear node deleted successfully");
        count--;
        printf("\nThe total elements are %d", count);
    }
}
void delete_by_position()
{
    struct node *temp, *temp1;
    int position, i;
    printf("\nEnter the position of the node to delete");
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
            for(i=0;i<position;i++)
            {
                temp1 = temp;
                temp = temp->next;
                if(temp == NULL)
                {
                    printf("\nCannot delete the last element");
                }
            }
            temp1->next = temp->next;
            temp->next->prev = temp1;
            temp->next = temp->prev =NULL;
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
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &key);  
    temp = head; 
    if(head->data == key) 
    {
        front_deletion();
    }
    else
    { 
        while(temp->data != key)  
        {
            temp = temp->next;  
        }
        if(temp->next == NULL && temp->data == key)  
        {  
            rear_deletion()  ;
        }  
        else if(temp->data == key)  
        {  
            temp1= temp->next;  
            temp->next = temp1->next;  
            temp1->next->prev = temp;  
            free(temp);  
            count--;
            printf("\nSpecified node deleted successfully");
            printf("\nThe total elements are %d", count);
        }     
        else
        {
            printf("\nKey Element not found\nEnter valid key element");
        }
    }
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
        while(temp != NULL)
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
void sort()
{
    struct node *temp, *temp1;
    int h;
    temp = head;
    while (temp != NULL)
    {
        temp1 = temp->next;
        while (temp1 != 0)
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
        while(temp!=NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
    }
}
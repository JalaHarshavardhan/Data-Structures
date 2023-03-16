// polynomial addition using single linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int expo, coef;
    struct node *next;
};
struct node *Pnew, *Phead, *p, *Qnew, *Qhead, *q, *head;
void main()
{
    int choice;
    printf("\nEnter first polynomial credentials:");
    do
    {
        Pnew = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter coefficient:");
        scanf("%d", &Pnew->coef);
        printf("\nEnter exponent:");
        scanf("%d", &Pnew->expo);
        Pnew->next = NULL;
        if(Phead == NULL)
        {
            Phead = Pnew;
            p = Pnew;
        }
        else
        {
            p->next = Pnew;
            p = Pnew;
        }
        printf("\nDo you want to add another term ? (0/1):");
        scanf("%d", &choice);
    }while(choice);
    // display first polynomial
    p = Phead;
    printf("\nFirst polynomial is :");
    while(p != NULL)
    {
        printf("%dx^%d", p->coef, p->expo);
        p = p->next;
        if(p != NULL)
        {
            printf(" + ");
        }
    }
    printf("\nEnter second polynomial credentials:");
    do
    {
        Qnew = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter coefficient:");
        scanf("%d", &Qnew->coef);
        printf("\nEnter exponent:");
        scanf("%d", &Qnew->expo);
        Qnew->next = NULL;
        if(Qhead == NULL)
        {
            Qhead = Qnew;
            q = Qnew;
        }
        else
        {
            q->next = Qnew;
            q = Qnew;
        }
        printf("\nDo you want to add another term ? (0/1):");
        scanf("%d", &choice); 
    }while(choice);

// display second polynomial
    q = Qhead;
    printf("\nSecond polynomial is :");
    while(q != NULL)
    {
        printf("%dx^%d", q->coef, q->expo);
        q = q->next;
        if(q != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n-------------------------------------------------\n");
    p = Phead;
    q = Qhead;
    while(p != NULL && q != NULL)
    {
        if(p->expo == q->expo)
        {
            printf("%dx^%d", p->coef + q->coef, p->expo);
            p = p->next;
            q = q->next;
        }
        else if(p->expo > q->expo)
        {
            printf("%dx^%d", p->coef, p->expo);
            p = p->next;
        }
        else
        {
            printf("%dx^%d", q->coef, q->expo);
            q = q->next;
        }
        if(p != NULL || q != NULL)
        {
            printf(" + ");
        }
    }
    while(p != NULL)
    {
        printf("%dx^%d", p->coef, p->expo);
        p = p->next;
        if(p != NULL)
        {
            printf(" + ");
        }
    }
    while(q != NULL)
    {
        printf("%dx^%d", q->coef, q->expo);
        q = q->next;
        if(q != NULL)
        {
            printf(" + ");
        }
    }
}
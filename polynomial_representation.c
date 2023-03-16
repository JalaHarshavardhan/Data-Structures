// polynomial addition using single linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef, expo;
    struct node *next;
};
struct node *Pnew, *Phead, *p;
void main()
{
    int choice;
    printf("\nEnter polynomial credentials:");
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
}
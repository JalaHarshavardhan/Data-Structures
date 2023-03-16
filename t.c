#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[100];
int top = -1;
void push(char x)
{
	stack[++top] = x;
}

char pop()
{
	if(top == -1)
	{
		return -1;
	}
	else
	{
		return stack[top--];
	}
}

int priority(char x)
{
	if(x == '(')
	{
		return 0;
	}
	if(x == '+' || x == '-')
	{
		return 1;
	}
	if(x == '*' || x == '/')
	{
		return 2;
	}
	return 0;
}

void main()
{
	char exp1[50], exp2[50];
	char *e, x;
    int len, i, j, a, b;
	printf("Enter the Infix expression:");
	scanf("%s", &exp1);
	printf("Infix expression: %s\n", exp1);
    printf("\nBefore reversing : %s\n", exp1);
    len = strlen(exp1);
    printf("Length of the string is %d", len);
    j = len - 1;
    for(i=0; i<len; i++)
    {
        exp2[i] = exp1[j];
        j--;
    }
    exp2[i] = '\0';
    printf("\nAfter reversing : %s\n", exp2);
	e = exp2;
	printf("Postfix expression for %s is: ", exp1);
	while(*e != '\0')
	{
		if(isalnum(*e))
		{
			printf("%c", *e);
		}
		else if(*e == ')')
		{
			push(*e);
		}
		else if(*e =='(')
		{
			while((x = pop()) != ')')
				printf("%c", x);
		}
		else
		{
			while(priority(stack[top]) >= priority(*e))
			{
				printf("%c", pop());
			}
			push(*e);
		}
		e++;
	}
	while(top != -1)
	{
		printf("%c", pop());
	}

    b = len - 1;
    for(a=0; a<len; a++)
    {
        exp2[a] = exp1[b];
        b--;
    }
    exp2[a] = '\0';
}
#include<stdio.h>
#include<ctype.h>
int stack[20];
int top = -1;
void push (int x)
{
	stack[++top] = x;
}
int pop ()
{
	return stack[top--];
}
void main ()
{
	char exp[44];
	char *e;
	int a, b, c, num;
	printf ("Enter the POSTFIX expression: ");
	scanf ("%s", exp);
	e = exp;
	while (*e != '\0')
    {
		if (isdigit (*e))
		{			// ascii value of '0' is 48-->
		num = *e - 48;	// here we are subtracting *e with 48 because 
		push (num);		// at first *e is a character type and to make it as a integer or decimal             
		}			// we are subtracting the character from 48 i.e., the ascii value of zero 
		else
		{
			a = pop ();
			b = pop ();
			switch (*e)
			{
				case '+': 
					c = a + b;
					break;
				case '-':
					c = b - a;
					break;
				case '*':
					c = a * b;
					break;
				case '/':
					c = b / a;
					break;
			}
			push (c);
		}
		e++;
    }
  printf ("\nThe result of expression %s = %d\n\n", exp, pop ());
}


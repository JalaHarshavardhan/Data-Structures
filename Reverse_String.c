#include<stdio.h>
#include<string.h>
void main()
{
    char str[50], rev[50];
    int len, i, j;
    printf("enter a string:");
    scanf("%s", &str);
    printf("\nBefore reversing : %s\n", str);
    len = strlen(str);
    printf("Length of the string is %d", len);
    j = len - 1;
    for(i=0; i<len; i++)
    {
        rev[i] = str[j];
        j--;
    }
    rev[i] = '\0';
    printf("\nAfter reversing : %s\n", rev);
}
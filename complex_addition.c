// complex number addition
#include<stdio.h>
struct complex
{
    int real;
    int imaginary;
};
void main()
{
    struct complex c1,c2,s;
    printf("Enter the real part c1:\n");
    scanf("%d",&c1.real);
    printf("Enter the imaginary part for c1:\n");
    scanf("%d",&c1.imaginary);
    printf("Enter the real part for c2:\n");
    scanf("%d",&c2.real);
    printf("Enter the real part for c2:\n");
    scanf("%d",&c2.imaginary);
    s.real=c1.real+c2.real;
    s.imaginary=c1.imaginary+c2.imaginary;
    printf("Sum: %d + %di\n",s.real,s.imaginary);
}
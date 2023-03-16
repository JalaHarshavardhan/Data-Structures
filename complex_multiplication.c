// complex number multiplcation
#include<stdio.h>
struct complex
{
    int real;
    int img;
};
void main()
{
    struct complex c1,c2,s;
    printf("Enter the real part for c1:\n");
    scanf("%d",&c1.real);
    printf("Enter the imaginary part for c1:\n");
    scanf("%d",&c1.img);
    printf("Enter the real part for c2:\n");
    scanf("%d",&c2.real);
    printf("Enter the real part for c2:\n");
    scanf("%d",&c2.img);
    s.real=((c1.real)*(c2.real)-(c1.img)*(c2.img));
    s.img=((c1.real)*(c2.img))+((c1.img)*(c2.real));
    printf("Multiplication: %d + %di\n",s.real,s.img);
}
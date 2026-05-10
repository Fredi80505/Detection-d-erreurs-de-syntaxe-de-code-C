#include<stdio.h>
int main()
{
    int a;
    int b;
    int c;

    printf("enter the first number");
    scanf("%d",&a);

    printf("enter the second number");
    scanf("%d",&b);

    printf("enter the third variable");
    scanf("%d",&c);

    if (a>b && a>c)
    {
        printf("a is the biggest");
    }
    
    if (b>c)
    {
        printf("b is the biggest");
    }
    
    else
    {
        printf("c is the biggest");
    }

}
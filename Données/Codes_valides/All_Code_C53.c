#include<stdio.h>
int main()
{
    int a;
    int b,temp;

    printf("enter the first number \t");
    scanf("%d",&a);

    printf("enter the second number\t");
    scanf("%d",&b);
    
    a=a+b;
    b=a-b;
    a=a-b;

    printf("the new first variable is:\t %d",a);

    printf("the new second variable is: \t%d",b);
    
}
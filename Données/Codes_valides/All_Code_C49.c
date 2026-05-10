#include<stdio.h>

int main()
{
    int num1,num2,sum=0;

    printf("Enter 1st Number:\n"); 
    scanf("%d",&num1);
    
    printf("Enter 2nd Number:\n");
    scanf("%d",&num2);

    sum=num1+num2;

    printf("The sum of %d and %d is: %d",num1, num2, sum);

    return 0;
}
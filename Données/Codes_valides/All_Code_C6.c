#include<stdio.h>
int main()
{
    int a;
    int b;
    printf("enter the 1st variable");
    scanf("%d",&a);

    printf("enter the 2nd variable");
    scanf("%d", &b);
     if(a>b)
     {
        printf("a is the biggest");
     }
     else
     {
        printf("b is the biggest");
     }
}
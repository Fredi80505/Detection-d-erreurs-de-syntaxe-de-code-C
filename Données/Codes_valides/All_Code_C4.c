#include<stdio.h>

int main ()
{
    int r, sum=0;
    int n;
    int b;

    printf("enter the number");
    scanf("%d",&n);
    b=n;
    while (n>0)
    {
        r=n%10;
        sum=sum+(r*r*r);
        n=n/10;
    }
    
    if (b==sum)
    {
        printf("it's a armstrong number",b);
    }
    else
    {
        printf("it's not a armstrong number",b);
    }
    
    return 0;
}
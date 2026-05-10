#include<stdio.h>
int main()
{
    int n,r;

    printf("enter the number");
    scanf("%d",&n);

    
    while (n>0)
    {
        r=n%10;

        if (r==0)
        {
            printf("the entered number is a duck number");
        }

        n=n/10;
        
    }
}
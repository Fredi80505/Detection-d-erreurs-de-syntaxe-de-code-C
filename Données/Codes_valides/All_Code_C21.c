#include<stdio.h>
int main ()
{
    int n,b,r,sum=0;

    printf("enter the number");
    scanf("%d",&n);
    b=n;

    while(n>0)
    {
        r=n%10;
        sum=sum+r;
        n=n/10;
    }

    if (b%sum!=0)
    {
        printf("the entered number is not a niven number");
    }
    else if(b%sum==0)
    {
        printf("the entered number is a niven number");
    }
    

}
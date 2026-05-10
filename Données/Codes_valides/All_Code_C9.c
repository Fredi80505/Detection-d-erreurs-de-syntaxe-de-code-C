#include<stdio.h>
int main()
{
    int n,r,last_digit=0;

    printf("enter the number");
    scanf("%d",&n);
    
        r=n%10;
        last_digit=last_digit+r;

        if (last_digit==7)
        {
            printf("the entered number is a buzz number");
        }
        
    
        else if (n%7==0)
        {
            printf("the entered number is a buzz number");
        }
        else
        {
            printf("the entered number is not a buzz number");
        }

}
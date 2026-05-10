#include<stdio.h>
int main()
{
    int i;
    int sum=0;
    int n;

    printf("enter the number to which u want the sum");
    scanf("%d",&n);

    for ( i=0;i<=n; i++)
    
    {
        sum=sum+i;
    }
    
    printf("the sum is:%d ",sum);
}
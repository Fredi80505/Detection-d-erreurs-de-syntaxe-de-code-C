#include<stdio.h>
int main()
{
    int i,j,k,n;
    printf("enter the no. of * u want at the top");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
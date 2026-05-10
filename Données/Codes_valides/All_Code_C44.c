#include<stdio.h>
int main()
{
    int n,i,j,k;
    printf("Enter the number highest no. of * u want in first line: ");
    scanf("%d",&n);

    for ( i = 1; i <=n; i++)
    {
        
    for ( j = 1; j <= i; j++)
    {
        printf("*");
    }
    printf("\n");
    
    }
    
}
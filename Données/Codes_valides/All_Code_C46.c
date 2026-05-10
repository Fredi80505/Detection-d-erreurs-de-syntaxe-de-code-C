#include <stdio.h>
int main()
{
    int r,i, j, k, number=1;

    printf("enter the number of rows u want to print upto");
    scanf("%d", &r);

    for ( i = 1; i <= r; i++)
    {
        for ( j = 1; j <=i ; j++)
        {
            printf("%d \t", number);
            number++;
        }
        printf("\n");
    }
    
}
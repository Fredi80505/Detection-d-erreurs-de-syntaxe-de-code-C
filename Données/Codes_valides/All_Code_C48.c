#include <stdio.h>
int main()
{
    int i, j, k, n;
    printf("enter the no of * u want in rhoumbus side's ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (k = 0; k < n; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}
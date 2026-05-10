#include <stdio.h>
int main()
{
    int r, i, j, k, l, m, n;
    printf("enter the rows");
    scanf("%d", &r);
    for (i = 1; i <= r; i++)
    {
        for (j = 0; j <= r - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (m = 2; m <= r; m++)
    {
        for (n = 1; n <= m; n++)
        {
            printf("*");
        }
        printf("\n");
    }
}
#include <stdio.h>
int main()
{
    int m, sum1 = 0, i, j, sum2 = 0;

    printf("enter the range of the matrix");
    scanf("%d", &m);

    int arr[m][m];

    printf("enter the elements into the array");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("the entered matrix is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == j)
            {
                sum1 = sum1 + arr[i][j];
            }
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i + j == m - 1)
            {
                sum2 = sum2 + arr[i][j];
            }
        }
    }

    printf("sum of left diagonal elements is %d", sum1);
    printf("sum of right diagonal elements is %d", sum2);
}
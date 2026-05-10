#include <stdio.h>
int main()
{
    int m, sum1,sum2, i, j;

    printf("Enter the range of the matrix \n");
    scanf("%d", &m);

    int arr[m][m];

    printf("Enter the elements into the array as follows \n\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter the elements into the position:(%d,%d) \n",i,j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The entered matrix is:\n");
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
        sum1=0;
        for (j = 0; j < m; j++)
        {
            sum1  = sum1 + arr[i][j];
        }
        printf("Sum of Row %d: %d \n",i,sum1);
    }

    for (j = 0; j < m; j++)
    {
        sum2=0;
        for (i = 0; i < m; i++)
        {
            sum2  = sum2 + arr[i][j];
        }
        printf("Sum of Column %d: %d \n",j,sum2);
    }  

    return 0;  
}
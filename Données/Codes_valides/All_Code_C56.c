#include <stdio.h>
int main()
{
    int m, sum = 0, i, j;

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

    printf("the transpose of the matrix is: \n");
    for ( i = 0; i < m; i++)
    {
        printf("\n");
        for ( j = 0; j < m; j++)
        {
            printf("%d \t",arr[j][i]);
        }
        
    }
    
}
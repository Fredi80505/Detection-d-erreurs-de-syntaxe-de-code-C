#include <stdio.h>
int factorial(int x)
{
    if (x == 1 || x == 0)
    {
        return 1;
    }
    else
    {
        return (x * factorial(x - 1));
    }
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int fac = factorial(number);
    printf("the factorial value of the number %d is:%d", number, fac);
}
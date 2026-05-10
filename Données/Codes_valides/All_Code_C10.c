#include <stdio.h>

//This function returens the value of the sum of two numbers
int sum(int x, int y)
{
    int z = x + y;
    
    return z;
}
//This function returens the value of the sub of two numbers
int sub(int x, int y)
{
    int z = x - y;
    
    return z;
}
//This function returens the value of the div of two numbers
int div(int x, int y)
{
    int z = x / y;
    
    return z;
}
//This function returens the value of the multi of two numbers
int mul(int x, int y)
{
    int z = x * y;
    
    return z;
}

//This is main function
int main()
{
    int a, b, c, n;
    printf("We will calculate the basic mathematical operation with two variable\n");
    
    //Infinite loop to print the choice section
    while(1)
    {
        printf("Enter the operation you want to do:\n 1. Add\n 2. Sub\n 3. Div\n 4. Multi\n");
        scanf("%d", &n);
        
        if (n!=1 && n!=2 && n!=3 && n!=4)
        {
            goto label;
        }
        else
        {
            printf("Enter the value of first number:\t");
            scanf("%d", &a);
            
            printf("Enter the value of second number:\t");
            scanf("%d", &b);
            
            switch(n)
            {
                case 1:
                    c = sum(a, b);
                    printf("The sum of the numbers are\t%d\n", c);
                    break;
                    
                case 2:
                    if(a>b)
                    {
                        c = sub(a, b);
                        printf("The substraction of the numbers are\t%d\n", c);
                    }
                    else
                    {
                        printf("The first number %d is less then the second number %d\n", a,b);
                    }

                    break;

                case 3:
                    if(a>b && b!=0)
                    {
                        c = div(a, b);
                        printf("the division of the numbers are\t%d\n", c);
                    }
                    else if(a<b && a!=0)
                    {
                        printf("The first number %d is less then the second number %d\n", a,b);
                    }
                    else if(a<b && a==0)
                    {
                        printf("the division of the numbers are\t0\n");
                    }
                    else if(b==0)
                    {
                        printf("the division of the numbers are\tUndefined\n");
                    }
                    
                    break;
                    
                case 4:
                    c = mul(a, b);
                    printf("The multiplication of the numbers are\t%d\n", c);
                    break;    
            label:
                default:
                printf("You have entered a wrong choice\n");
                        
                    break;
            }
    }
    }
    return 0;
}
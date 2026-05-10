#include<stdio.h>
int main()
{
    int a;

    printf("enter the number:\n");
    scanf("%d",&a);

    int* pntr;

    pntr= &a;
    printf("value of the enter pointer is:%d \n", *pntr); //to print the value of the pointer
    printf("The Address of pointer is %p\n", &pntr ); //to print the address of the pointer
	printf("The Address of a is %p\n", a); // to print the address of the variable a typically in hexadecimal format. The %p format specifier is specifically used to print pointer values.
	printf("The Address of pointer in another way without using & and by using percent p instead of percent d is %p\n",pntr ); // to print the address of the pointer in another way
    printf("The Value of a is %d\n", *pntr );


    return 0;
}
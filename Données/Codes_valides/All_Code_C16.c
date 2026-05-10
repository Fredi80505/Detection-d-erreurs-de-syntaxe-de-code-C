#include<stdio.h>

void main()
{
 
    float h=0;
    int side=0;
    
    printf("enter the length of the side of the equilateral triangle:");
    scanf("%d", &side);
    
    h=((side*1.73)/2);
    
    printf("the height is: %f", h);
    

}
#include<stdio.h>

void main()
{
 
    float area=0;
    int side=0;
    
    printf("enter the length of the side of the hexagon:");
    scanf("%d", &side);
    
    area=((side*side*1.732*3)/2);
    
    printf("the height is: %f", area);
    

}
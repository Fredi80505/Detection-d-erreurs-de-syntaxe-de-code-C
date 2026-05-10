#include<stdio.h>

void main()
{
 
    float r=0;
    float h=0;
    float area=0;
    float py=3.14;    
    printf("enter the radius:");
    scanf("%f", &r);
    
    printf("enter the height:");
    scanf("%f", &h);
    
    area=((2*py*r*h)+(2*py*r*r));
    
    printf("the area is: %f", area);
    
}
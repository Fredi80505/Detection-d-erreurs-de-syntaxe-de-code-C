#include<stdio.h>

int main()
{
    float r=0;
    float py=3.14;
    float area=0;
    
    printf("Enter the radius:");
    scanf("%f", &r);
    
    area= py*r*r;
    
    printf("The area is: %f", area);
}
#include<stdio.h>

void main()
{
 
    float c=0;
    float f=0;
    
    printf("enter the celcius temperature:");
    scanf("%f", &c);
    
    f=((9*c+160)/5);
    
    printf("the fahrenheit temp is: %f", f);
    

}
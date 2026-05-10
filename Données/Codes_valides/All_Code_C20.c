#include <stdio.h>
  
int main ()  
{  
    int n, temp,c, rev = 0, digit, sum = 0;   
    printf (" Enter a Number:");  
    scanf (" %d", &n); 
    temp = n;   
    while ( temp > 0)  
    {
        sum = sum + temp % 10;   
        temp = temp / 10;  
    }  
    c = sum;
      
    while ( c > 0)  
    {  
        rev = rev * 10 + c % 10;  
        c = c / 10;  
    }
    if ( rev * sum == n)  
    {  
        printf (" it is a Magic Number. ", n);  
    }  
    else
    {  
        printf (" it is not a Magic Number. ", n);  
    }  
    return 0;  
      
}
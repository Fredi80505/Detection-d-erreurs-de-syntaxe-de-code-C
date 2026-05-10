#include<stdio.h>
#include<string.h>
int main()
{
    int n,count=0;
    char s[10];
    
    printf("enter the string array elements\n");
    scanf("%s", s);
    printf("the entered string array is:%s\n", s);
    
    while(s[count]!='\0')
    {
        count++;
    }
    
    printf("the length of the string is:%d", count);
    
}
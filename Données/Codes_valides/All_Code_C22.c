#include<stdio.h>
#include<string.h>

int main()
{
  char s[100];

  printf("enter the number for your string:\n");
  scanf("%s",s);

  int len= strlen(s);

  printf("the length of your string is :%d", len);

}

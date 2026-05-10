// Online C compiler to run C program online
#include<stdio.h>

int main()
{
  int i,r,t,num,count,con=2,sum;

  printf("Enter number\n");
  scanf("%d",&num);

  while(con>1)
  {
    
    while(num>0)
    {
      r=num%10;
      sum=sum+(r*r);
      count++;
      num=num/10;
    }
    num=sum;
    printf("\n%d",sum);
    printf("\n%d",count);
    con=count;
    count=0;
    sum=0;
}

  if(sum==1)
  {
    printf("\nHappy Number\n");
  }
  else
  {
    printf("\nUnHappy Number\n");
  }

  return 0;
}
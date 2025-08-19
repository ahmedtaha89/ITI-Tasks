#include <stdio.h>
void main(void)
{
 int x;
 int *ptr1=&x;
 int y;
 int*ptr2=&y;
 int sum;
 printf("Enter the first value \n");
 scanf("%d",ptr1);
 printf("Enter the second value \n");
 scanf("%d",ptr2);
 sum=*ptr1+*ptr2;
 printf("The sum of two values = %d",sum);



}


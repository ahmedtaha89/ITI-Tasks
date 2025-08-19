#include <stdio.h>
void main(void)
{
 int arr[5];
 int *ptr;
 ptr=arr;
 for(int i=0;i<5;i++)
 {
     printf("Enter the value[%d] of the array :",i+1);
     scanf("%d",&arr[i]);
 }

 for(int i=0;i<5;i++)
 {
     printf("The values you entered are : %d\n",*ptr++);
 }


}


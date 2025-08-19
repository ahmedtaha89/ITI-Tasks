#include <stdio.h>
void swap(int * a,int * b);
void main(void)
{

int num1;
int num2;
int *ptr1;
int *ptr2;
ptr1=&num1;
ptr2=&num2;

printf("Enter the first number \n");
scanf("%d",ptr1);
printf("Enter the second number \n");
scanf("%d",&num2);

printf("Before Swapping : \n");
printf("The First number is : %d \n",*ptr1);
printf("The Second number is : %d \n",*ptr2);

swap(ptr1,ptr2);

printf("After Swapping : \n");
printf("The First number is : %d \n",*ptr1);
printf("The Second number is : %d \n",*ptr2);

}
void swap(int * a,int * b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


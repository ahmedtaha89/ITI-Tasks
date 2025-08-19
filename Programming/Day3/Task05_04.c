#include <stdio.h>
int sum_iter (int arr[],int size);
int sum_rec (int arr[],int size);
void main(void) {

int size;
printf("Enter The size of the array \n");
scanf("%d",&size);
int arr[size];
for(int i=0;i<size;i++)
    {
    printf("Enter the value[%d] in the array : \n",i+1);
    scanf("%d",&arr[i]);
    }

printf("The sum of the values using iteration : %d \n",sum_iter(arr,size));
printf("The sum of the values using Recursion : %d",sum_rec(arr,size));

}
int sum_iter(int arr[],int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
        sum+=arr[i];
    return sum;
}
int sum_rec(int arr[],int size)
{
    int sum=0;
    if(size==0)
    return sum;
    else
    {
        return arr[size - 1] + sum_rec(arr, size - 1);
    }
}

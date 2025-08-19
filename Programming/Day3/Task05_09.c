#include <stdio.h>
int print_arr(int arr[],int size);
void main(void)
{
    int size1;
    int size2;
    int count=0;
    printf("Enter the size of array 1 \n");
    scanf("%d",&size1);
    int arr1[size1];
     for(int i=0;i<size1;i++)     //intializing the array
    {
     printf("Enter the value[%d] of the array ",i+1);
     scanf("%d",&arr1[i]);
    }
     printf("Enter the size of array 2 \n");
     scanf("%d",&size2);
     int arr2[size2];
     for(int i=0;i<size2;i++)     //intializing the array
    {
     printf("Enter the value[%d] of the array ",i+1);
     scanf("%d",&arr2[i]);
    }

    int size3=size1+size2;
    int arr3[size3];
    for(int i=0;i<size1;i++)     //intializing the array
     arr3[i]=arr1[i];

     for(int i=size1;i<size3;i++)
     {
        arr3[i]=arr2[count];
        count++;
     }

    print_arr(arr3,size3);



}
int print_arr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    printf("The value in position[%d] = %d \n",i,arr[i]);
}

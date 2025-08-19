#include <stdio.h>
int print_arr(int arr[],int size);
void main(void) {
    int size;
    printf("The size of the array is : \n");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)     //intializing the array
    {
     printf("Enter the value[%d] of the array ",i+1);
     scanf("%d",&arr[i]);
    }
    print_arr(arr,size);
}

int print_arr(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("The value in position[%d] = %d \n",i,arr[i]);
}

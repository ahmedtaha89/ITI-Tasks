#include <stdio.h>
int print_arr(int arr[],int size);
void main(void) {
    int size;
    int count;
    printf("The size of the array is : \n");
    scanf("%d",&size);
    int arr[size];
    count=size-1;
    for(int i=0;i<size;i++)     //intializing the array
    {
     printf("Enter the value[%d] of the array ",i+1);
     scanf("%d",&arr[i]);
    }
    printf("The array before being reversed : \n");
    print_arr(arr,size);
    printf("The array after being reversed : \n");
    for(int i=0;i<size;i++)
    {
        int temp;
        temp=arr[i];
        arr[i]=arr[count];
        arr[count]=temp;
        count--;
        if(i>=count)
            break;
    }
    print_arr(arr,size);
}

int print_arr(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("The value in position[%d] = %d \n",i,arr[i]);
}


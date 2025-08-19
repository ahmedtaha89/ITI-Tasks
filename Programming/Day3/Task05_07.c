#include <stdio.h>
int print_arr(int arr[],int size);
int bubble_sort(int arr[],int size);
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
    printf("Data Before Sort : \n");
    print_arr(arr,size);
    bubble_sort(arr,size);
    printf("Data After Sort : \n");
    print_arr(arr,size);
}

int print_arr(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("The value in position[%d] = %d \n",i,arr[i]);
}
int bubble_sort(int arr[],int size)
{
    int sorted;
    do{
        sorted = 1;
        for(int i=0;i<size-1;i++)
        {
            {
            if(arr[i+1]<arr[i]){
                int temp;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                sorted=0;
                }
            }
        }
    }while(!sorted);
    return arr[size];
}

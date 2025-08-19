#include <stdio.h>
int print_arr(int arr[],int count);
void main(void) {
    int count=0;
    int arr[20];
    for(int i=0;i<5;i++)     //intializing the array
    {
     printf("Enter the value[%d] of the array ",i+1);
     scanf("%d",&arr[i]);
     count++;
    }
    for(int i=0;i<count;i++)         //loop to sort the array if its not sorted
    {
        for(int j=0;j<count;j++)
            if(arr[i]<arr[j])
        {
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    printf("Lets sort the array \n");
    for(int i=0;i<count;i++)
        printf("The value in position[%d] = %d \n",i,arr[i]);

    printf("Insert new value in the array \n");
    scanf("%d",&arr[count]);
    count++;
    for(int i=0;i<count;i++)         //loop to sort the array if its not sorted
    {
    for(int j=0;j<count;j++)
        if(arr[i]<arr[j])
        {
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    print_arr(arr,count);
}

int print_arr(int arr[],int count)
{
    for(int i=0;i<count;i++)
        printf("The value in position[%d] = %d \n",i,arr[i]);
}

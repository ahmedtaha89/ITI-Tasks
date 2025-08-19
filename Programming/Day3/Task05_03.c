#include<stdio.h>
int getmax(int arr[],int size);
void main(void)
{
    int size;
    int max;
    printf("Enter How many numbers you want to add \n");
    scanf("%d",&size);
    int arr[size];

    for(int i=0;i<size;i++)
    {
        printf("Enter the numbers \n");
        scanf("%d",&arr[i]);
    }
    max = getmax(arr, size);
    printf("The maximum number = %d",max);

}

int getmax(int arr[],int size)
{
    int max=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        else
            continue;
    }
    return max;
}


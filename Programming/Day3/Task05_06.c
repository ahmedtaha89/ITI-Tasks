#include <stdio.h>
int binary_search(int arr[],int low,int high,int value);
void main(void) {
    int size;
    int pos;
    int value;
    printf("Enter the array size \n");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
     printf("Enter the value[%d] of the array ",i+1);
     scanf("%d",&arr[i]);
    }
    for(int i=0;i<size;i++)         //loop to sort the array if its not sorted
    {
        for(int j=0;j<size;j++)
            if(arr[i]<arr[j])
        {
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    printf("Enter the value you want to search about  \n");
    scanf("%d",&value);
    printf("The Value you entered in position number %d",binary_search(arr,0,size-1,value));

}
int binary_search(int arr[],int low,int high,int value)
{
    if(low>high)
        return -1;
    int mid =(low+high)/2;
    if(arr[mid]==value)
        return mid;
    else if(arr[mid]>value)
        binary_search(arr,low,mid-1,value);
    else
        binary_search(arr,mid+1,high,value);

}

#include <stdio.h>
int linear_search(int arr[],int size,int value);
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
    printf("Enter the value you want to search about  \n");
    scanf("%d",&value);
    printf("The Value you entered in position number %d",linear_search(arr,size,value));

}
int linear_search(int arr[],int size,int value)
{
    int pos;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==value)
        {
            pos=i+1;
            break;
        }
        else
            pos=-1;

    }
    return pos;

}

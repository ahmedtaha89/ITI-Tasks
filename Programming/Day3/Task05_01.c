#include<stdio.h>
void main(void)
{
    int n;
    int even[10];
    int odd[10];
    int count_even=0;
    int count_odd=0;

    for (int i=0;i<10;i++)
    {
        printf("Enter the numbers \n");
        scanf("%d",&n);
        if(n%2==0){
            even[count_even]=n;
            count_even++;
        }
        else
        {
        odd[count_odd]=n;
        count_odd++;

        }
    }
    for(int i=0;i<count_odd;i++)
    {
        printf("The array of odd numbers %d \n",odd[i]);
    }
    for(int i=0;i<count_even;i++)
    {
        printf("The array of even numbers %d \n ",even[i]);
    }


}

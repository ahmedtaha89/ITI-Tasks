#include <stdio.h>
#include <stdlib.h>
void main(void)
{
    int * data;
    int size;
    int max;

    printf("Enter the size of the array \n");
    scanf("%d",&size);

    data = (int *) malloc (size* sizeof(int));

    for(int i=0;i<size;i++)
    {
        printf("Enter the value[%d]\n",i+1);
        scanf("%d",&data[i]);
    }

    max=*data;

   for(int i=0;i<size;i++)
    {
        if(*data>max)
            max=*data;
            data++;

    }
    printf("The maximum number is = %d ",max);

}



#include <stdio.h>
void main(void)
{
    int count=0;
    char *name="Kareem";
    printf("Your name is : %s\n",name);
    while(*name != '\0')
    {
        *name++;
        count++;
    }
    printf("The length of string is %d ",count);
}


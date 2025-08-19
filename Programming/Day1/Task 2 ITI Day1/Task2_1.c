#include <stdio.h>

int main()
{
    int number;
    printf("Please Enter Number: ");
    scanf("%d",&number);
    
    if (number > 0)
        printf("Number %d is Positive",number);
    
    else if (number < 0)
        printf("Number (%d) is Negative",number);

    else if (number == 0)
        printf("Number %d is Zero",number);


    return 0;
}

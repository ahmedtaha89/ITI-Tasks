#include <stdio.h>

int main()
{
    int Grade;
    printf("Enter Your Grade: ");
    scanf("%d",&Grade);

    if(Grade >= 90)
        printf("Excellent");

    else if(Grade >= 80 && Grade < 90)
        printf("Very Good");

    else if(Grade >= 65 && Grade < 80)
        printf("Good");
     
    else if(Grade >= 50 && Grade < 65)
        printf("Pass");

    else if(Grade < 50)
        printf("Fail");
    
    return 0;
}

#include <stdio.h>

int main()
{
    int number;
    printf("Enter Number: ");
    scanf("%d", &number);
    (number > 0) ? printf("Positive\n") : (number == 0) ? printf("Zero\n") : printf("Negative\n");
    return 0;
}

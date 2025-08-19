#include <stdio.h>

int main(void)
{
    int num = 0;
    int first = 0;
    int second = 0;

    printf("Enter the number (0 - 99): ");
    scanf("%d", &num);

    if (num < 0 || num > 99)
        printf("Out of range (0 - 99)");

    if (num == 0) printf("Zero");
    else if (num == 1) printf("One");
    else if (num == 2) printf("Two");
    else if (num == 3) printf("Three");
    else if (num == 4) printf("Four");
    else if (num == 5) printf("Five");
    else if (num == 6) printf("Six");
    else if (num == 7) printf("Seven");
    else if (num == 8) printf("Eight");
    else if (num == 9) printf("Nine");
    else if (num == 10) printf("Ten");
    else if (num == 11) printf("Eleven");
    else if (num == 12) printf("Twelve");
    else if (num == 13) printf("Thirteen");
    else if (num == 14) printf("Fourteen");
    else if (num == 15) printf("Fifteen");
    else if (num == 16) printf("Sixteen");
    else if (num == 17) printf("Seventeen");
    else if (num == 18) printf("Eighteen");
    else if (num == 19) printf("Nineteen");
    else
    {
        first = num / 10;
        second = num % 10;

        if (first == 2) printf("Twenty");
        else if (first == 3) printf("Thirty");
        else if (first == 4) printf("Forty");
        else if (first == 5) printf("Fifty");
        else if (first == 6) printf("Sixty");
        else if (first == 7) printf("Seventy");
        else if (first == 8) printf("Eighty");
        else if (first == 9) printf("Ninety");

        if (second != 0)
        {
            if (second == 1) printf("One");
            else if (second == 2) printf("Two");
            else if (second == 3) printf("Three");
            else if (second == 4) printf("Four");
            else if (second == 5) printf("Five");
            else if (second == 6) printf("Six");
            else if (second == 7) printf("Seven");
            else if (second == 8) printf("Eight");
            else if (second == 9) printf("Nine");
        }
    }

    return 0;
}

#include <stdio.h>

void swapTwoNumbers(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);

    swapTwoNumbers(&num1, &num2);
    printf("   First number  = %d\n", num1);
    printf("   Second number = %d\n", num2);

    return 0;
}

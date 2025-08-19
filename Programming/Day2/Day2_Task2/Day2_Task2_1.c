#include <stdio.h>

void bin_iterative(int num) {
    int pow = 1;
    while (pow <= num / 2) {
        pow *= 2;}

    printf("Binary (iterative): ");

    while (pow > 0) {
        if (pow <= num) {
            printf("1");
            num -= pow;
        } else {
            printf("0");
        }
        pow /= 2;
    }

    printf("\n");
}

void bin_recursive(int num) {
    if (num == 0)
        return;
    
    bin_recursive(num / 2);
    printf("%d", num % 2);
}

int main() {
    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    bin_iterative(num);

    printf("Binary (recursive): ");
    if (num == 0)
        printf("0");
    else
        bin_recursive(num);

    printf("\n");

    return 0;
}

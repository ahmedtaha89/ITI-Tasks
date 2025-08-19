#include <stdio.h>

int calculatePowerLoop(int base, int exponent) {
    int power = 1;
    for (int i = 0; i < exponent; i++) {
        power *= base;
    }
    return power;
}

int calculatePowerRecursive(int base, int exponent) {
    if (exponent == 0)
        return 1;
    return base * calculatePowerRecursive(base, exponent - 1);
}

int main() {
    int baseNumber, exponentValue;

    printf("Enter base number: ");
    scanf("%d", &baseNumber);

    printf("Enter exponent (non-negative): ");
    scanf("%d", &exponentValue);

    while (exponentValue < 0) {
        printf("Exponent must be non-negative. Try again: ");
        scanf("%d", &exponentValue);
    }

    printf("\nResult using loop => %d ** %d = %d\n",
           baseNumber, exponentValue, calculatePowerLoop(baseNumber, exponentValue));

    printf("Result using recursion => %d ** %d = %d\n",
           baseNumber, exponentValue, calculatePowerRecursive(baseNumber, exponentValue));

    return 0;
}

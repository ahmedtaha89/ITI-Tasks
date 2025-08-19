#include <stdio.h>

int computeFactorialLoop(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int computeFactorialRecursive(int n) {
    return (n == 0) ? 1 : n * computeFactorialRecursive(n - 1);
}

int main() {
    int value;
    printf("Please input a non-negative integer to calculate its factorial: ");
    scanf("%d", &value);

    while (value < 0) {
        printf(" Error: Factorial is not defined for negative numbers.\n");
        printf("Try again with a non-negative number: ");
        scanf("%d", &value);
    }

    int loopResult = computeFactorialLoop(value);
    int recursiveResult = computeFactorialRecursive(value);

    printf("\nFactorial of %d using loop = %d\n", value, loopResult);
    printf("Factorial of %d using recursion = %d\n", value, recursiveResult);

    return 0;
}

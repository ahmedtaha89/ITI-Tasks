#include <stdio.h>

int getSumIterative(int n) {
    return n * (n + 1) / 2;
}

int getSumRecursive(int n) {
    if (n == 0)
        return 0;
    return n + getSumRecursive(n - 1);
}

int main() {
    int number;

    printf("Enter positive number: ");
    scanf("%d", &number);

    while (number <= 0) {
        printf("Number must be greater than 0. Try again: ");
        scanf("%d", &number);
    }

    int sumIter = getSumIterative(number);
    int sumRec  = getSumRecursive(number);

    printf("\nSum using Iterative %d = %d\n", number, sumIter);
    printf("Sum using Recursive  %d = %d", number, sumRec);

    return 0;
}

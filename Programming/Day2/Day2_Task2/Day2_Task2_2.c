#include <stdio.h>
#include <stdbool.h>

int isPrime(int number) {
    if (number < 2)
        return false;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }

    return true;
}

int main() {
    int input;

    printf("Enter a positive number to check if it's prime: ");
    scanf("%d", &input);

    while (input < 1) {
        printf("Number must be greater than 0. Try again: ");
        scanf("%d", &input);
    }

    if (isPrime(input)) {
        printf("%d is prime number\n", input);
    } else {
        printf("%d is not prime number", input);
    }

    return 0;
}

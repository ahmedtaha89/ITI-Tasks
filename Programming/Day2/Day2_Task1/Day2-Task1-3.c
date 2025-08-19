#include <stdio.h>

int main() {
    int n;
    float number, max, min;

    printf("Please Enter Number of Inputs: ");
    scanf("%d", &n);

    printf("Enter number (1): ");
    scanf("%f", &number);
    max = number;
    min = number;

    for (int i = 2; i <= n; i++) {
        printf("Enter number (%d): ", i);
        scanf("%f", &number);

        if (number > max)
            max = number;

        if (number < min)
            min = number;
    }

printf("Maximum = %.2f, Minimum = %.2f, Range = %.2f\n", max, min, max - min);
    return 0;
}

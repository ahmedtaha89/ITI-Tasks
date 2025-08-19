#include <stdio.h>

int main() {
    int n, number, max;

    printf("Please Enter Number of Inputs: ");
    scanf("%d", &n);
    
    printf("Please Enter Number (1): ");
    scanf("%d", &number);
    max = number; 

    for (int i = 2; i <= n; i++) {
        printf("Please Enter Number (%d): ", i);
        scanf("%d", &number);

        if (number > max) {
            max = number;
        }
    }

    printf("Max Number: %d", max);
    return 0;
}

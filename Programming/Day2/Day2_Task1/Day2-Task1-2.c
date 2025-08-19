#include <stdio.h>

int main() {
    int n, number, min;

    printf("Please Enter Number of Inputs: ");
    scanf("%d", &n);
    
    printf("Please Enter Number (1): ");
    scanf("%d", &number);
    min = number; 

    for (int i = 2; i <= n; i++) {
        printf("Please Enter Number (%d): ", i);
        scanf("%d", &number);

        if (number < min) {
            min = number;
        }
    }

    printf("Min Number: %d", min);
    return 0;
}

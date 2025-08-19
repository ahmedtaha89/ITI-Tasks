#include <stdio.h>

int main() {
    int num, count, sum = 0;
    float avg;

    printf("Please Enter Number of Inputs: ");
    scanf("%d", &count);

    for (int i = 1; i <= count; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        sum += num;
    }

    avg = (float)sum / count;
    printf("Average = %.2f\n", avg);

    return 0;
}

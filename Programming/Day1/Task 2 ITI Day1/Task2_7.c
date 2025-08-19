#include <stdio.h>
#define ZERO_TAX_LIMIT 7000.0
#define FIRST_BRACKET_LIMIT 20000.0
#define SECOND_BRACKET_LIMIT 45000.0
#define THIRD_BRACKET_LIMIT 200000.0

#define FIRST_RATE   0.10
#define SECOND_RATE  0.15
#define THIRD_RATE   0.20
#define FOURTH_RATE  0.40

int main() {
    float salary, tax = 0.0;

    printf("Enter your annual salary: ");
    scanf("%f", &salary);

    if (salary <= ZERO_TAX_LIMIT) {
        tax = 0.0;
    }
    else if (salary <= FIRST_BRACKET_LIMIT) {
        tax = (salary - ZERO_TAX_LIMIT) * FIRST_RATE;
    }
    else if (salary <= SECOND_BRACKET_LIMIT) {
        tax = (FIRST_BRACKET_LIMIT - ZERO_TAX_LIMIT) * FIRST_RATE +
              (salary - FIRST_BRACKET_LIMIT) * SECOND_RATE;
    }
    else if (salary <= THIRD_BRACKET_LIMIT) {
        tax = (FIRST_BRACKET_LIMIT - ZERO_TAX_LIMIT) * FIRST_RATE +
              (SECOND_BRACKET_LIMIT - FIRST_BRACKET_LIMIT) * SECOND_RATE +
              (salary - SECOND_BRACKET_LIMIT) * THIRD_RATE;
    }
    else {
        tax = (FIRST_BRACKET_LIMIT - ZERO_TAX_LIMIT) * FIRST_RATE +
              (SECOND_BRACKET_LIMIT - FIRST_BRACKET_LIMIT) * SECOND_RATE +
              (THIRD_BRACKET_LIMIT - SECOND_BRACKET_LIMIT) * THIRD_RATE +
              (salary - THIRD_BRACKET_LIMIT) * FOURTH_RATE;
    }

    printf("Tax amount: %.2f\n", tax);
    return 0;
}
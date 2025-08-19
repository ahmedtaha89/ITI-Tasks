#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, root, x1, x2;

    printf("Please Enter Values:\n");
    printf("Enter Value of a: ");
    scanf("%lf", &a);
    printf("Enter Value of b: ");
    scanf("%lf", &b);
    printf("Enter Value of c: ");
    scanf("%lf", &c);

    delta = b*b - 4*a*c;

    if (delta > 0) {
        root = sqrt(delta);
        x1 = (-b + root) / (2*a);
        x2 = (-b - root) / (2*a);
        printf("Two distinct real roots:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
    else if (delta == 0) {
        x1 = -b / (2*a);
        printf("One repeated real root:\n");
        printf("x = %.2f\n", x1);
    }
    else 
        printf("No real roots.");
    

    return 0;
}

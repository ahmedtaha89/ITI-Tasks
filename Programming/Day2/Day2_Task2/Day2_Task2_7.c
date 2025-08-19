#include <stdio.h>
#include <math.h>

double fac(int n) {
    if (n == 0 || n == 1) return 1;
    else return n * fac(n - 1);
}

int main() {
    double x;

    printf("Enter value in radians: ");
    scanf("%lf", &x);
    x = x * M_PI / 180.0;

    double res = 0;
    double s = 1;
    for (double i = 1; i < 10; i += 2) {
        res += s * (pow(x, i) / fac(i));
        s *= -1;
    }

    printf("sin(%.2f) ≈ %.6f\n", x, res);

    return 0;
}

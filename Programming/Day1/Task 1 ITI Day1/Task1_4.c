#include <stdio.h>

int main() {

    float base, height, area;
    printf("Enter base a triangle: ");
    scanf("%f", &base);
    printf("Enter height a triangle: ");
    scanf("%f", &height);
    area = 0.5 * base * height;
    printf("Area of the triangle = %.2f", area);
    return 0;
}

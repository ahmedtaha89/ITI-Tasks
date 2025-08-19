#include <stdio.h>
int main()
{    
    float Length, area;
    printf("Please Enter Length: ");
    scanf("%f",&Length);
    area = Length * Length;
    printf("Area of a square: %.2f",area);
    return 0;
}

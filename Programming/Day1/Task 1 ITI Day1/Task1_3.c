#include <stdio.h>
#define PI 3.14

int main()
{  
    // const float PI = 3.14; 
    float Area , radius;
    printf("Please Enter radius: ");
    scanf("%f",&radius);
    Area = PI * (radius * radius);
    printf("Area Of Circle: %.3f",Area);
    return 0;
}

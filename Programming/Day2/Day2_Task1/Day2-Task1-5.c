#include <stdio.h>
#include <limits.h>

int main() {
    int num , n;
    int max = INT_MIN, 
    secondMax = INT_MIN;
    int min = INT_MAX, 
    secondMin = INT_MAX;

    printf("Please Enter Number of Inputs: ");
    scanf("%d", &n);

    printf("Enter %d numbers: \n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        if (num > max) {
            secondMax = max;
            max = num; 
        } 
        else if (num > secondMax && num != max) 
            secondMax = num;
        

        if (num < min) {
            secondMin = min;
            min = num;
        } 
        else if (num < secondMin && num != min)
            secondMin = num;
        
    }
printf("Second Max = %d,Second Min = %d\n",secondMax , secondMin);

return 0;
}

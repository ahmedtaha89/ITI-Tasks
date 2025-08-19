#include <stdio.h>
#include <conio.h>

int main() {
    char ch;
    int number = 0;
    int digit_count = 0;

    printf("Enter a number (max 5 digits): ");

    while (1) {
        ch = getch();

        if (ch == 13) break;
        if (ch >= '0' && ch <= '9') {
            if (digit_count < 5) {
                printf("%c", ch); 
                number = number * 10 + (ch - '0');
                digit_count++;
            }
        }

        else if (ch == 8 && digit_count > 0) {
            printf("\b \b");
            number /= 10;
            digit_count--;
        }

    }

    printf("\nNumber: %d\n", number);
    return 0;
}
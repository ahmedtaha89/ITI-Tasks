#include <stdio.h>

int main()
{
    int amount, coins = 0;

    printf("Please Enter Amount: ");
    scanf("%d", &amount);

    coins += amount / 50;
    amount %= 50;

    coins += amount / 25;
    amount %= 25;

    coins += amount / 10;
    amount %= 10;

    coins += amount / 5;
    amount %= 5;

    coins += amount / 1;
    amount %= 1;

    printf("coins: %d", coins);

    return 0;
}

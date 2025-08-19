#include <stdio.h>
int getStringLength(char *input) {
    int length = 0;
    while (input[length] != '\0')
        length++;
    return length;
}

int main() {
    char originalString[100];
    char reversedString[100];

    printf("Enter a string: ");
    scanf("%s", originalString);

    int length = getStringLength(originalString);

    for (int i = 0; i < length; i++)
        reversedString[length - i - 1] = originalString[i];

    reversedString[length] = '\0';

    printf("Reversed string: %s\n", reversedString);

    return 0;
}


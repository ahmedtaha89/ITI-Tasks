#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char *name1 = malloc(100 * sizeof(char));
    char *name2 = malloc(100 * sizeof(char));
    int count1 = 0;
    int count2 = 0;
    int size = 0;
    int i;

    printf("Enter the first name: ");
    scanf("%s", name1);

    printf("Enter the second name: ");
    scanf("%s", name2);

    char *tmp1 = name1;
    char *tmp2 = name2;

    while (*tmp1 != '\0') {
        tmp1++;
        count1++;
    }
    printf("Length of first name = %d\n", count1);

    while (*tmp2 != '\0') {
        tmp2++;
        count2++;
    }
    printf("Length of second name = %d\n", count2);

    size = (count1 > count2) ? count1 : count2;

    for (i = 0; i < size; i++) {
        if (*(name1 + i) > *(name2 + i)) {
            printf("The first name is greater than the second one.\n");
            break;
        } else if (*(name2 + i) > *(name1 + i)) {
            printf("The second name is greater than the first one.\n");
            break;
        }
    }

    if (i == size) {
        if (count1 > count2)
            printf("Name 1 is greater (longer).\n");
        else if (count2 > count1)
            printf("Name 2 is greater (longer).\n");
        else
            printf("Both names are the same.\n");
    }
}


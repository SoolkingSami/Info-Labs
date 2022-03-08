#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIM 101

int main() {
    srand(time(NULL));
    char str[DIM];
    printf("Enter the string to be shuffled:\n");
    scanf("%s", str);

    int len = strlen(str);
    int i, j;
    char temp;
    for (i = 0; i < len; i++) {
        j = rand() % len;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("The shuffled string is:\n%s\n", str);

    return 0;
}

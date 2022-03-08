#include <stdio.h>
#include <string.h>

#define DIM 101

void str_sort(char *src) {
    int i, j;
    char tmp;
    for (i = 0; i < strlen(src); i++) {
        for (j = i + 1; j < strlen(src); j++) {
            if (src[i] > src[j]) {
                tmp = src[i];
                src[i] = src[j];
                src[j] = tmp;
            }
        }
    }
}

int main() {
    char str_base[DIM], str_test[DIM];
    printf("Enter the base string:\n");
    scanf("%s", str_base);

    printf("Enter the sub string:\n");
    scanf("%s", str_test);

    str_sort(str_base);
    str_sort(str_test);

    if (strcmp(str_base, str_test) == 0) {
        printf("The second string is an anagram of the first string.\n");
    } else {
        printf("The second string is not an anagram of the first string.\n");
    }

    return 0;
}

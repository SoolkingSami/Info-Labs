#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *ai = "Inteligenta Artificiala", *c = "Limbajul C";
    srand(time(NULL));
    int r = rand() % 2;
    if (r == 0) {
        printf("%s\n", ai);
    } else {
        printf("%s\n", c);
    }

    return 0;
}

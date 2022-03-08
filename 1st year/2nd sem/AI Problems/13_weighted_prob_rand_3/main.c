#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *ai = "Inteligenta Artificiala", *c = "Limbajul C", *web = "Programare Web";
    srand(time(NULL));
    int r = rand() % 3;
    switch (r) {
        case 0:
            printf("%s\n", ai);
            break;
        case 1:
            printf("%s\n", c);
            break;
        case 2:
            printf("%s\n", web);
            break;
        default:
            printf("Nu exista aceasta optiune\n");
            break;
    }

    return 0;
}

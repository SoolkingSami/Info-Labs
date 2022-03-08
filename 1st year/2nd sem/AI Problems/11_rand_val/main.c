#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 99;
    srand(time(NULL));
    int r = rand() % n + 1;
    printf("The random number is %d\n", r);

    return 0;
}

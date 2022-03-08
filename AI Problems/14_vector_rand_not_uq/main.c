#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int m;
    printf("Enter the number of elements to be randomly selected:\n");
    scanf("%d", &m);

    int *arr2 = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        int index = rand() % n;
        arr2[i] = arr[index];
    }

    printf("The elements randomly selected are:\n");
    for (int i = 0; i < m; ++i) {
        printf("%d ", arr2[i]);
    }

    int max = arr2[0];
    for (int i = 1; i < m; ++i) {
        if (arr2[i] > max) {
            max = arr2[i];
        }
    }

    printf("\nThe maximum element is %d\n", max);

    free(arr2);
    free(arr);
    return 0;
}
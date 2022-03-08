#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int val;
    printf("Enter the value to be inserted:\n");
    scanf("%d", &val);

    arr = (int *)realloc(arr, (n + 1) * sizeof(int));
    int i = 0;
    while (i < n && arr[i] < val) {
        ++i;
    }
    for (int j = n; j > i; --j) {
        arr[j] = arr[j - 1];
    }
    arr[i] = val;
    ++n;

    printf("The array after insertion:\n");
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

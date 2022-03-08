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

    printf("The array before insertion:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    int val, pos;
    printf("\nEnter the value to be inserted:\n");
    scanf("%d", &val);
    printf("Enter the position:\n");
    scanf("%d", &pos);

    arr = (int *)realloc(arr, (n + 1) * sizeof(int));
    for (int i = n - 1; i >= pos; --i) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    ++n;

    printf("The array after insertion:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

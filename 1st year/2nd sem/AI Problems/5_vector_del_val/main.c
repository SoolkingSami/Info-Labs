#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The array before deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int pos;
    printf("\nEnter the position:\n");
    scanf("%d", &pos);

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    --n;

    printf("The array after deleting the element at position %d is:\n", pos);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

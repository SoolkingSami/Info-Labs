#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The array before deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int val;
    printf("\nEnter the value to be deleted:\n");
    scanf("%d", &val);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            count++;
        }
    }

    int *new_arr = (int *)malloc((n - count) * sizeof(int));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != val) {
            new_arr[j] = arr[i];
            j++;
        }
    }

    arr = new_arr;
    n -= count;
    printf("\nThe array after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

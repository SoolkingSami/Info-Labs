#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));
    int *arr3 = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Enter the elements of the third array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr3[i]);
    }

    printf("The first array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\nThe second array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    printf("\nThe third array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr3[i]);
    }

    int flag = 0;

    for (int i = 0; i < n; i++) {
        if (!(arr1[i] < arr2[i] && arr2[i] < arr3[i])) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("\nThe array is valid.\n");
    } else {
        printf("\nThe array is invalid.\n");
    }

    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}

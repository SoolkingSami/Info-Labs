#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int order_by_pivot(int* arr, int start, int end) {
    int pivot = arr[start];
    int i = start;
    int j = end;
    while (i < j) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    arr[start] = arr[j];
    arr[j] = pivot;
    return j;
}

void quick_sort(int* arr, int start, int end) {
    if (start < end) {
        int pivot = order_by_pivot(arr, start, end);
        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("The array before sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("\nThe array after sorting:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

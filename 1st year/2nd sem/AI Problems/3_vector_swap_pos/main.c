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

    printf("The array before swapping:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int pos1, pos2;
    printf("\nEnter the first position:\n");
    scanf("%d", &pos1);
    printf("Enter the second position:\n");
    scanf("%d", &pos2);

    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;

    printf("The array after swapping:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

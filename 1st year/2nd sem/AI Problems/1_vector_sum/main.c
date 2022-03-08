#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("The sum is: %d", sum);

    free(arr);
    return 0;
}

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

    int val;
    printf("Enter the value to be searched:\n");
    scanf("%d", &val);

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("%d is present at index %d\n", val, i);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("%d is not present in the array\n", val);
    }

    free(arr);
    return 0;
}

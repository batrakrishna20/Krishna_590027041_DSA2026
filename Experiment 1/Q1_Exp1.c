#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    arr = (int*)malloc(n * sizeof(int));

    // Check allocation
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display elements
    printf("Array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free memory
    free(arr);
    arr = NULL;

    return 0;
}

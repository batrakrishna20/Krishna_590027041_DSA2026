#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *a = (int*)malloc(n * sizeof(int));
    int i, largest, smallest;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize largest and smallest
    largest = smallest = a[0];
    // Find largest and smallest
    for (i = 1; i < n; i++) {
        if (a[i] > largest)
            largest = a[i];
        if (a[i] < smallest)
            smallest = a[i];
    }

    // Output results
    printf("Largest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);
    free(a);
    a = NULL;
    return 0;
}


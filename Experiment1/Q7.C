#include <stdio.h>

int main() {
    int n, pos, x;
    int arr[100];   // maximum size

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position (1-based)
    printf("Enter position to insert (1-based): ");
    scanf("%d", &pos);

    // Input element to insert
    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Shift elements to the right
    for (int i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert element
    arr[pos - 1] = x;

    // Display updated array
    printf("Updated array:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

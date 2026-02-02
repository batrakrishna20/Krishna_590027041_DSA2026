#include <stdio.h>

int main() {
    int n;
    int arr[100];

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display elements in reverse order
    printf("Array in reverse order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    return 0;
}

Output: 
Enter number of elements: 2 
Enter 2 elements:
42 46
Array in reverse order:
46 42 

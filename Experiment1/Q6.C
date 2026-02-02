#include <stdio.h>

int main() {
    int n, key;
    int arr[100];
    int found = 0;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            found = 1;
            break;
        }
    }

    // If not found
    if (!found) {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}


Output:
Enter number of elements: 3
Enter 3 elements:
32 454 2
Enter element to search: 2
Element 2 found at position 3


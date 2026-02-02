#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i, largest, smallest;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize largest and smallest
    largest = smallest = arr[0];

    // Find largest and smallest
    for (i = 1; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
        if (arr[i] < smallest)
            smallest = arr[i];
    }

    // Output results
    printf("Largest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);

    return 0;
}

Output: 
Enter number of elements: 9
Enter 9 elements:
1 35 556 656 64 67 77 35 56
Largest element = 656
Smallest element = 1



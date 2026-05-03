#include <stdio.h>

int main() {
    int n, i, j, temp;
    int comp = 0, swap = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            comp++;
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap++;
            }
        }

        printf("Pass %d: ", i+1);
        for(int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }

    printf("Sorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nComparisons = %d\nSwaps = %d\n", comp, swap);

    return 0;
}
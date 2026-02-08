#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, x;
    int *a;
    int sum = 0;
    float avg;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int*)malloc((n + 1) * sizeof(int));

    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to insert (1-based): ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        free(a);
        return 1;
    }

    printf("Enter element to insert: ");
    scanf("%d", &x);

    for (int i = n - 1; i >= pos - 1; i--) {
        a[i + 1] = a[i];
    }

    a[pos - 1] = x;
    n++;  

    printf("Updated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
        sum += a[i];
    }

   
    avg = sum / (float)n;

    printf("\nSum = %d", sum);
    printf("\nAverage = %.2f", avg);

    free(a);
    a = NULL;

    return 0;
}

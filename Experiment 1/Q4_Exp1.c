#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    int **A, **B, **sum, **diff;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    A = (int **)malloc(r * sizeof(int *));
    B = (int **)malloc(r * sizeof(int *));
    sum = (int **)malloc(r * sizeof(int *));
    diff = (int **)malloc(r * sizeof(int *));

    for (int i = 0; i < r; i++) {
        A[i] = (int *)malloc(c * sizeof(int));
        B[i] = (int *)malloc(c * sizeof(int));
        sum[i] = (int *)malloc(c * sizeof(int));
        diff[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            diff[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("\nMatrix Addition (A + B):\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix Subtraction (A - B):\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++) {
        free(A[i]);
        free(B[i]);
        free(sum[i]);
        free(diff[i]);
    }
    free(A);
    free(B);
    free(sum);
    free(diff);

    return 0;
}

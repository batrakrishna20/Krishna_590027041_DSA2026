#include <stdio.h>

int main() {
    int n;
    int marks[100][5];   // maximum 100 students
    int i, j, total;
    float percentage;

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input marks
    for (i = 0; i < n; i++) {
        printf("Enter marks of student %d (5 subjects):\n", i + 1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    // Calculate and print total & percentage
    printf("\nStudent Results:\n");
    for (i = 0; i < n; i++) {
        total = 0;
        for (j = 0; j < 5; j++) {
            total += marks[i][j];
        }
        percentage = total / 5.0;

        printf("Student %d: Total = %d, Percentage = %.2f%%\n",
               i + 1, total, percentage);
    }

    return 0;
}

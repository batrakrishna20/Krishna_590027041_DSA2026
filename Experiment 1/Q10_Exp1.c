#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n, i, j;
    struct Student *s, temp;

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    s = (struct Student *)malloc(n * sizeof(struct Student));

    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Sorting by marks (ascending order)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].marks > s[j].marks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Display sorted records
    printf("\nStudent records sorted by marks:\n");
    for (i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }

    // Free memory
    free(s);
    s = NULL;

    return 0;
}

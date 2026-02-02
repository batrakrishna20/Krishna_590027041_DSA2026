#include <stdio.h>

int main() {
    int sub1[20], sub2[20];
    int i;

    // Input marks
    printf("Enter marks for Subject 1:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &sub1[i]);
    }

    printf("Enter marks for Subject 2:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &sub2[i]);
    }

    // Print total marks
    printf("\nTotal marks of each student:\n");
    for (i = 0; i < 20; i++) {
        printf("Student %d: %d\n", i + 1, sub1[i] + sub2[i]);
    }

    return 0;
}

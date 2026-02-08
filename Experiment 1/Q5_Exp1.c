#include <stdio.h>
#include <stdlib.h>


struct Student {
    int roll;
    char name[50];
    float gpa;
    char course[30];
};

int main() {
    int n;
    struct Student *s;

    printf("Enter number of students: ");
    scanf("%d", &n);

    s = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);   

        printf("GPA: ");
        scanf("%f", &s[i].gpa);

        printf("Course: ");
        scanf(" %[^\n]", s[i].course);
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("GPA: %.2f\n", s[i].gpa);
        printf("Course: %s\n", s[i].course);
    }

    free(s);

    return 0;
}

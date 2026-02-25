#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student *next;
} Student;

Student* create_student(int roll, const char *name, float marks) {
    Student *s = (Student*)malloc(sizeof(Student));
    if (!s) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->roll = roll;
    strncpy(s->name, name, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    s->marks = marks;
    s->next = NULL;
    return s;
}

Student* search(Student *head, int roll) {
    for (Student *cur = head; cur != NULL; cur = cur->next) {
        if (cur->roll == roll) return cur;
    }
    return NULL;
}

// Insert at end; prevent duplicate roll
void insert(Student **head, int roll, const char *name, float marks) {
    if (search(*head, roll) != NULL) {
        printf("Roll number %d already exists. Insert failed.\n", roll);
        return;
    }

    Student *n = create_student(roll, name, marks);

    if (*head == NULL) {
        *head = n;
        return;
    }

    Student *cur = *head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = n;
}

void display(Student *head) {
    if (!head) {
        printf("No records.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Roll", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (Student *cur = head; cur != NULL; cur = cur->next) {
        printf("%-10d %-20s %-10.2f\n", cur->roll, cur->name, cur->marks);
    }
}

void delete_record(Student **head, int roll) {
    if (*head == NULL) {
        printf("No records to delete.\n");
        return;
    }

    Student *cur = *head, *prev = NULL;
    while (cur != NULL && cur->roll != roll) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Roll number %d not found.\n", roll);
        return;
    }

    if (prev == NULL) { // deleting head
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }

    free(cur);
    printf("Record with roll %d deleted.\n", roll);
}

void free_all(Student *head) {
    while (head) {
        Student *t = head;
        head = head->next;
        free(t);
    }
}

int main() {
    Student *head = NULL;
    int choice, roll;
    char name[50];
    float marks;

    while (1) {
        printf("\n--- Student Record Menu ---\n");
        printf("1. Insert record\n");
        printf("2. Delete record\n");
        printf("3. Search record\n");
        printf("4. Display all records\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter roll: ");
                scanf("%d", &roll);
                printf("Enter name (no spaces): ");
                scanf("%49s", name);
                printf("Enter marks: ");
                scanf("%f", &marks);
                insert(&head, roll, name, marks);
                break;

            case 2:
                printf("Enter roll to delete: ");
                scanf("%d", &roll);
                delete_record(&head, roll);
                break;

            case 3: {
                printf("Enter roll to search: ");
                scanf("%d", &roll);
                Student *s = search(head, roll);
                if (s) {
                    printf("Found: Roll=%d, Name=%s, Marks=%.2f\n", s->roll, s->name, s->marks);
                } else {
                    printf("Roll number %d not found.\n", roll);
                }
                break;
            }

            case 4:
                display(head);
                break;

            case 0:
                free_all(head);
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    free_all(head);
    return 0;
}
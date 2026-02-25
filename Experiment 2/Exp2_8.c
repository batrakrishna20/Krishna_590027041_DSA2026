#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

int main() {
    Node *head = NULL;
    int choice, x, n;

    printf("\n--- Doubly Circular Linked List (Single Function) ---\n");
    printf("1. Create list (n nodes)\n");
    printf("2. Display\n");
    printf("3. Count nodes\n");
    printf("4. Insert at beginning\n");
    printf("5. Insert at end\n");
    printf("6. Delete from beginning\n");
    printf("7. Delete from end\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) return 0;

    if (choice == 0) return 0;

    switch (choice) {
        case 1: { // Create list
            printf("How many nodes? ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &x);

                Node *newNode = (Node*)malloc(sizeof(Node));
                if (!newNode) { printf("Memory allocation failed!\n"); return 1; }
                newNode->data = x;

                if (head == NULL) {
                    head = newNode;
                    head->next = head;
                    head->prev = head;
                } else {
                    Node *last = head->prev;
                    newNode->next = head;
                    newNode->prev = last;
                    last->next = newNode;
                    head->prev = newNode;
                }
            }
            break;
        }

        case 2: { // Display (needs a list first)
            printf("Display chosen, but list is empty in this single-run program.\n");
            printf("Use option 1 (Create) or modify program to keep looping.\n");
            break;
        }

        case 3: { // Count (needs a list first)
            printf("Count chosen, but list is empty in this single-run program.\n");
            printf("Use option 1 (Create) or modify program to keep looping.\n");
            break;
        }

        case 4: { // Insert at beginning (demo: create first, then insert)
            printf("How many nodes to create first? ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &x);

                Node *newNode = (Node*)malloc(sizeof(Node));
                if (!newNode) { printf("Memory allocation failed!\n"); return 1; }
                newNode->data = x;

                if (head == NULL) {
                    head = newNode;
                    head->next = head;
                    head->prev = head;
                } else {
                    Node *last = head->prev;
                    newNode->next = head;
                    newNode->prev = last;
                    last->next = newNode;
                    head->prev = newNode;
                }
            }

            printf("Enter value to insert at beginning: ");
            scanf("%d", &x);

            Node *newNode = (Node*)malloc(sizeof(Node));
            if (!newNode) { printf("Memory allocation failed!\n"); return 1; }
            newNode->data = x;

            if (head == NULL) {
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                Node *last = head->prev;
                newNode->next = head;
                newNode->prev = last;
                last->next = newNode;
                head->prev = newNode;
                head = newNode;
            }
            break;
        }

        case 5: { // Insert at end (demo: create first, then insert)
            printf("How many nodes to create first? ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &x);

                Node *newNode = (Node*)malloc(sizeof(Node));
                if (!newNode) { printf("Memory allocation failed!\n"); return 1; }
                newNode->data = x;

                if (head == NULL) {
                    head = newNode;
                    head->next = head;
                    head->prev = head;
                } else {
                    Node *last = head->prev;
                    newNode->next = head;
                    newNode->prev = last;
                    last->next = newNode;
                    head->prev = newNode;
                }
            }

            printf("Enter value to insert at end: ");
            scanf("%d", &x);

            Node *newNode = (Node*)malloc(sizeof(Node));
            if (!newNode) { printf("Memory allocation failed!\n"); return 1; }
            newNode->data = x;

            if (head == NULL) {
                head = newNode;
                head->next = head;
                head->prev = head;
            } else {
                Node *last = head->prev;
                newNode->next = head;
                newNode->prev = last;
                last->next = newNode;
                head->prev = newNode;
            }
            break;
        }

        case 6: { // Delete from beginning (demo: create first, then delete)
            printf("How many nodes to create first? ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &x);

                Node *newNode = (Node*)malloc(sizeof(Node));
                if (!newNode) { printf("Memory allocation failed!\n"); return 1; }
                newNode->data = x;

                if (head == NULL) {
                    head = newNode;
                    head->next = head;
                    head->prev = head;
                } else {
                    Node *last = head->prev;
                    newNode->next = head;
                    newNode->prev = last;
                    last->next = newNode;
                    head->prev = newNode;
                }
            }

            if (head == NULL) {
                printf("List is empty. Nothing to delete.\n");
            } else if (head->next == head) {
                free(head);
                head = NULL;
            } else {
                Node *last = head->prev;
                Node *temp = head;
                head = head->next;
                last->next = head;
                head->prev = last;
                free(temp);
            }
            break;
        }

        case 7: { // Delete from end (demo: create first, then delete)
            printf("How many nodes to create first? ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &x);

                Node *newNode = (Node*)malloc(sizeof(Node));
                if (!newNode) { printf("Memory allocation failed!\n"); return 1; }
                newNode->data = x;

                if (head == NULL) {
                    head = newNode;
                    head->next = head;
                    head->prev = head;
                } else {
                    Node *last = head->prev;
                    newNode->next = head;
                    newNode->prev = last;
                    last->next = newNode;
                    head->prev = newNode;
                }
            }

            if (head == NULL) {
                printf("List is empty. Nothing to delete.\n");
            } else if (head->next == head) {
                free(head);
                head = NULL;
            } else {
                Node *last = head->prev;
                Node *newLast = last->prev;
                newLast->next = head;
                head->prev = newLast;
                free(last);
            }
            break;
        }

        default:
            printf("Invalid choice.\n");
            break;
    }

    // Print list + count once, then exit (no loop)
    if (head == NULL) {
        printf("\nList: (empty)\n");
        printf("Count: 0\n");
    } else {
        int count = 0;
        Node *cur = head;

        printf("\nList: ");
        do {
            printf("%d ", cur->data);
            count++;
            cur = cur->next;
        } while (cur != head);

        printf("\nCount: %d\n", count);
    }

    // Free memory before exit
    if (head != NULL) {
        Node *cur = head->next;
        while (cur != head) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        free(head);
        head = NULL;
    }

    return 0;
}
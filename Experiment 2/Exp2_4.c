#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *start = NULL, *ptr, *newNode;
    int i, value;

    if (n <= 0)
        return NULL;

    printf("Enter data for node 1: ");
    scanf("%d", &value);

    start = (struct Node*)malloc(sizeof(struct Node));
    start->data = value;
    start->next = NULL;
    ptr = start;

    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        ptr->next = newNode;
        ptr = newNode;
    }

    return start;
}

void displayList(struct Node *start) {
    struct Node *ptr = start;

    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node* deleteBeginning(struct Node *start) {
    struct Node *ptr;

    if (start == NULL)
        return NULL;

    ptr = start;
    start = start->next;
    free(ptr);

    return start;
}

int main() {
    struct Node *start;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    start = createList(n);

    start = deleteBeginning(start);

    displayList(start);

    return 0;
}

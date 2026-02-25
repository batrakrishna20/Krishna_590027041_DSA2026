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

struct Node* insertafter(struct Node *start, int key, int value) {
    struct Node *prt, *newNode;

    prt = start;
    while (prt != NULL && prt->data != key)
        prt = prt->next;

    if (prt == NULL) {
        printf("Node not found\n");
        return start;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = prt->next;
    prt->next = newNode;

    return start;
}

int main() {
    struct Node *start;
    int n, key, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    start = createList(n);

    printf("Enter node value after which to insert: ");
    scanf("%d", &key);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    start = insertafter(start, key, value);

    displayList(start);

    return 0;
}
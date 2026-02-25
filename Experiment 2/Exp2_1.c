#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *start = NULL, *prt, *newNode;
    int i, value;

    if (n <= 0)
        return NULL;

    printf("Enter data for node 1: ");
    scanf("%d", &value);

    start = (struct Node*)malloc(sizeof(struct Node));
    start->data = value;
    start->next = NULL;
    prt = start;

    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        prt->next = newNode;
        prt = newNode;
    }

    return start;
}

void displayList(struct Node *start) {
    struct Node *prt = start;

    printf("Linked List: ");
    while (prt != NULL) {
        printf("%d -> ", prt->data);
        prt = prt->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node *start) {
    int count = 0;
    struct Node *prt = start;

    while (prt != NULL) {
        count++;
        prt = prt->next;
    }

    return count;
}

int main() {
    struct Node *start;
    int n, total;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    start = createList(n);

    displayList(start);

    total = countNodes(start);
    printf("Total number of nodes: %d\n", total);

    return 0;
}

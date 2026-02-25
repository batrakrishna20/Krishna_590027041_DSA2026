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

int searchElement(struct Node *start, int key) {
    int position = 1;
    struct Node *prt = start;

    while (prt != NULL) {
        if (prt->data == key)
            return position;
        prt = prt->next;
        position++;
    }
    return -1;
}

int main(){
    struct Node *start;
    int n, key, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

     start = createList(n);

    printf("Enter element to search: ");
    scanf("%d", &key);
    pos = searchElement(start, key);

    if (pos != -1)
        printf("Element found at position: %d\n", pos);
    else
        printf("Element not found in the list.\n");

    return 0;
}
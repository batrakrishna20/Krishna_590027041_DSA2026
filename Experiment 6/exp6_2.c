#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// Insert
void insert(int val) {
    heap[size] = val;
    heapifyUp(size);
    size++;
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Delete root
void deleteRoot() {
    if (size == 0) {
        printf("Heap empty\n");
        return;
    }
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Display
void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Main
int main() {
    int choice, val;

    while (1) {
        printf("\n1.Insert 2.DeleteRoot 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                deleteRoot();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}
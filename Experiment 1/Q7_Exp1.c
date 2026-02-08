#include <stdio.h>
#include <stdlib.h>

struct Record {
    int id;
    char name[50];
};

int main() {
    struct Record *r = NULL;
    int n = 0, choice, i, delId;

    do {
        printf("\n1. Add\n2. Display\n3. Delete\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {

        case 1: // Add
            r = realloc(r, (n + 1) * sizeof(struct Record));
            printf("Enter id and name: ");
            scanf("%d %s", &r[n].id, r[n].name);
            n++;
            break;

        case 2: // Display
            for (i = 0; i < n; i++) {
                printf("%d %s\n", r[i].id, r[i].name);
            }
            break;

        case 3: // Delete
            printf("Enter id to delete: ");
            scanf("%d", &delId);

            for (i = 0; i < n; i++) {
                if (r[i].id == delId) {
                    r[i] = r[n - 1];  // replace with last
                    n--;
                    r = realloc(r, n * sizeof(struct Record));
                    break;
                }
            }
            break;

        case 4: // Exit
            free(r);
            break;
        }

    } while (choice != 4);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff;
    int exp;
    struct Term *next;
} Term;

Term* create_term(int c, int e) {
    Term *t = (Term*)malloc(sizeof(Term));
    if (!t) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    t->coeff = c;
    t->exp = e;
    t->next = NULL;
    return t;
}

// Insert in descending order of exponent; if exp matches, add coefficients
void insert_term(Term **head, int c, int e) {
    if (c == 0) return;

    Term *n = create_term(c, e);

    if (*head == NULL || (*head)->exp < e) {
        n->next = *head;
        *head = n;
        return;
    }

    Term *cur = *head, *prev = NULL;
    while (cur != NULL && cur->exp > e) {
        prev = cur;
        cur = cur->next;
    }

    if (cur != NULL && cur->exp == e) {
        cur->coeff += c;
        free(n);
        // Optional: if becomes 0, remove node
        if (cur->coeff == 0) {
            if (prev == NULL) {
                *head = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
        }
        return;
    }

    // insert between prev and cur
    prev->next = n;
    n->next = cur;
}

void display_poly(Term *head) {
    if (!head) {
        printf("Polynomial: 0\n");
        return;
    }

    printf("Polynomial: ");
    Term *cur = head;
    int first = 1;

    while (cur) {
        int c = cur->coeff;
        int e = cur->exp;

        if (c != 0) {
            if (!first) {
                if (c > 0) printf(" + ");
                else { printf(" - "); c = -c; }
            } else {
                if (c < 0) { printf("-"); c = -c; }
                first = 0;
            }

            if (e == 0) {
                printf("%d", c);
            } else if (e == 1) {
                if (c == 1) printf("x");
                else printf("%dx", c);
            } else {
                if (c == 1) printf("x^%d", e);
                else printf("%dx^%d", c, e);
            }
        }
        cur = cur->next;
    }
    printf("\n");
}

long long ipow(int x, int e) {
    long long res = 1;
    for (int i = 0; i < e; i++) res *= x;
    return res;
}

long long evaluate(Term *head, int x) {
    long long sum = 0;
    for (Term *cur = head; cur != NULL; cur = cur->next) {
        sum += (long long)cur->coeff * ipow(x, cur->exp);
    }
    return sum;
}

void free_poly(Term *head) {
    while (head) {
        Term *t = head;
        head = head->next;
        free(t);
    }
}

int main() {
    Term *poly = NULL;
    int choice, n, c, e, x;

    while (1) {
        printf("\n--- Polynomial Menu ---\n");
        printf("1. Create polynomial (enter n terms)\n");
        printf("2. Insert a term\n");
        printf("3. Display polynomial\n");
        printf("4. Evaluate at x\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                free_poly(poly);
                poly = NULL;
                printf("How many terms? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter coeff and exp for term %d: ", i + 1);
                    scanf("%d %d", &c, &e);
                    insert_term(&poly, c, e);
                }
                break;
            case 2:
                printf("Enter coeff and exp: ");
                scanf("%d %d", &c, &e);
                insert_term(&poly, c, e);
                break;
            case 3:
                display_poly(poly);
                break;
            case 4:
                printf("Enter x: ");
                scanf("%d", &x);
                printf("P(%d) = %lld\n", x, evaluate(poly, x));
                break;
            case 0:
                free_poly(poly);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    free_poly(poly);
    return 0;
}
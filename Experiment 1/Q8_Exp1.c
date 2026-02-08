#include <stdio.h>

// Define union
union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;

    // Store integer
    d.i = 10;
    printf("After storing integer:\n");
    printf("Integer: %d\n", d.i);

    // Store float
    d.f = 3.14;
    printf("\nAfter storing float:\n");
    printf("Float: %.2f\n", d.f);
    printf("Integer (overwritten): %d\n", d.i);

    // Store character
    d.c = 'A';
    printf("\nAfter storing character:\n");
    printf("Character: %c\n", d.c);
    printf("Float (overwritten): %.2f\n", d.f);

    // Size of union
    printf("\nSize of union: %lu bytes\n", sizeof(d));

    return 0;
}

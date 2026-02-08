#include <stdio.h>

// Structure definition
struct DataStruct {
    int i;
    float f;
    char c;
};

// Union definition
union DataUnion {
    int i;
    float f;
    char c;
};

int main() {

    printf("Size of structure: %lu bytes\n", sizeof(struct DataStruct));
    printf("Size of union: %lu bytes\n", sizeof(union DataUnion));

    return 0;
}

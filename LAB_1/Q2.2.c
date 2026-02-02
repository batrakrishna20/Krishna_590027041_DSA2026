#include <stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // Error case
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    
    unsigned long long result = factorial(n);
    
    if (result != 0) {
        printf("Factorial of %d is %llu\n", n, result);
    } else {
        printf("Factorial is not defined for negative numbers.\n");
    }
    
    return 0;
}

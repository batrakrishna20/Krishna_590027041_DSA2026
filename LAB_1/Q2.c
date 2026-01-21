#include <stdio.h>

int main() {
    int num, reversed = 0, remainder;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Handle negative numbers by taking absolute value
    int isNegative = (num < 0);
    if (isNegative) {
        num = -num;
    }
    
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    
    if (isNegative) {
        reversed = -reversed;
    }
    
    printf("Reversed number: %d\n", reversed);
    return 0;
}

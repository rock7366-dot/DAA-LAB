#include <stdio.h>

int main() {
    int n, digit;
    int present[10] = {0};

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Mark each digit that appears in the number
    while (n > 0) {
        digit = n % 10;
        present[digit] = 1;
        n = n / 10;
    }

    // Find the digit that is not present
    for (digit = 0; digit <= 9; digit++) {
        if (present[digit] == 0) {
            printf("Missing digit: %d\n", digit);
            break;
        }
    }

    return 0;
}
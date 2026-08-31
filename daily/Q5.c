#include <stdio.h>

int main() {
    int n, temp;
    int ones = 0, zeros = 0;
    int currentOnes = 0, maxConsecutiveOnes = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    // Special case for 0
    if (temp == 0) {
        printf("Binary representation: 0\n");
        printf("Number of 1s: 0\n");
        printf("Number of 0s: 1\n");
        printf("Maximum consecutive 1s: 0\n");
        return 0;
    }

    printf("Binary representation: ");

    // Convert number to binary
    // Since we get bits from right to left, store them in an array
    int binary[32];
    int i = 0;

    while (temp > 0) {
        binary[i] = temp % 2;
        temp = temp / 2;
        i++;
    }

    // Print binary representation from left to right
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\n");

    // Count 1s, 0s and consecutive 1s
    for (int j = 0; j < i; j++) {
        if (binary[j] == 1) {
            ones++;
            currentOnes++;

            if (currentOnes > maxConsecutiveOnes) {
                maxConsecutiveOnes = currentOnes;
            }
        } else {
            zeros++;
            currentOnes = 0;
        }
    }

    printf("Number of 1s: %d\n", ones);
    printf("Number of 0s: %d\n", zeros);
    printf("Maximum consecutive 1s: %d\n", maxConsecutiveOnes);

    return 0;
}
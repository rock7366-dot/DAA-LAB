#include <stdio.h>

int main() {
    int a[] = {-4, -3, -5, 1, 2, 3};
    int n = 6;

    int result[6];
    int i, j, temp;

    // Square each element
    for (i = 0; i < n; i++) {
        result[i] = a[i] * a[i];
    }

    // Sort the squared elements
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (result[i] > result[j]) {
                temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    // Print result
    printf("Output: ");
    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
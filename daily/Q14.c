#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr1[] = {1, 5, 19, 20, 30};
    int arr2[] = {2, 7, 25, 28, 35};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    int minDiff = abs(arr1[0] - arr2[0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int diff = abs(arr1[i] - arr2[j]);

            if (diff < minDiff) {
                minDiff = diff;
            }
        }
    }

    printf("Smallest difference = %d\n", minDiff);

    return 0;
}
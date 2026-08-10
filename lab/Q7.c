#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int k = 2;
    int i, temp;

    k = k % n;

    // Reverse complete array
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    // Reverse first K elements
    for (i = 0; i < k / 2; i++) {
        temp = arr[i];
        arr[i] = arr[k - 1 - i];
        arr[k - 1 - i] = temp;
    }

    // Reverse remaining elements
    for (i = k; i < k + (n - k) / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - (i - k)];
        arr[n - 1 - (i - k)] = temp;
    }

    printf("Rotated array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
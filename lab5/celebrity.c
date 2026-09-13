/*
DAA LAB - Experiment 5
Celebrity Problem

A celebrity is known by everyone but knows nobody.
*/

#include <stdio.h>

int findCelebrity(int a[][50], int n) {
    int candidate = 0;

    // Eliminate non-celebrity candidates.
    for (int i = 1; i < n; i++) {
        if (a[candidate][i] == 1)
            candidate = i;
    }

    // Verify the remaining candidate.
    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;

        if (a[candidate][i] == 1 || a[i][candidate] == 0)
            return -1;
    }

    return candidate;
}

int main(void) {
    int n;
    int a[50][50];

    printf("Enter number of people (max 50): ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Invalid number of people.\n");
        return 0;
    }

    printf("Enter the %dx%d matrix (1 = knows, 0 = does not know):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int celebrity = findCelebrity(a, n);

    if (celebrity == -1)
        printf("No celebrity exists.\n");
    else
        printf("Celebrity is person %d.\n", celebrity);

    return 0;
}

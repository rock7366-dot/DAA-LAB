/*
DAA LAB - Experiment 3
Sorting algorithms with time analysis.

Algorithms:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIndex]) minIndex = j;
        swap(&a[i], &a[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc((size_t)n1 * sizeof(int));
    int *R = malloc((size_t)n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    free(L); free(R);
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void copyArray(int dest[], const int src[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) return 0;

    int *original = malloc((size_t)n * sizeof(int));
    int *a = malloc((size_t)n * sizeof(int));
    if (!original || !a) return 1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &original[i]);

    clock_t start, end;

    copyArray(a, original, n);
    start = clock(); bubbleSort(a, n); end = clock();
    printf("Bubble Sort:    %.9f sec\n", (double)(end-start)/CLOCKS_PER_SEC);

    copyArray(a, original, n);
    start = clock(); selectionSort(a, n); end = clock();
    printf("Selection Sort: %.9f sec\n", (double)(end-start)/CLOCKS_PER_SEC);

    copyArray(a, original, n);
    start = clock(); insertionSort(a, n); end = clock();
    printf("Insertion Sort: %.9f sec\n", (double)(end-start)/CLOCKS_PER_SEC);

    copyArray(a, original, n);
    start = clock(); mergeSort(a, 0, n-1); end = clock();
    printf("Merge Sort:     %.9f sec\n", (double)(end-start)/CLOCKS_PER_SEC);

    copyArray(a, original, n);
    start = clock(); quickSort(a, 0, n-1); end = clock();
    printf("Quick Sort:     %.9f sec\n", (double)(end-start)/CLOCKS_PER_SEC);

    free(original);
    free(a);
    return 0;
}

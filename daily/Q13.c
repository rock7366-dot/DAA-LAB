#include <stdio.h>

int main()
{
    int nums1[] = {1, 3};
    int nums2[] = {2, 4};

    int m = 2, n = 2;
    int a[100];
    int i = 0, j = 0, k = 0;
    int total;
    float median;

    // Merge two sorted arrays
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
            a[k++] = nums1[i++];
        else
            a[k++] = nums2[j++];
    }

    // Copy remaining elements of nums1
    while (i < m)
        a[k++] = nums1[i++];

    // Copy remaining elements of nums2
    while (j < n)
        a[k++] = nums2[j++];

    total = m + n;

    // Find median
    if (total % 2 == 0)
        median = (a[total / 2 - 1] + a[total / 2]) / 2.0;
    else
        median = a[total / 2];

    printf("Merged Array: ");

    for (i = 0; i < total; i++)
        printf("%d ", a[i]);

    printf("\nMedian = %.2f", median);

    return 0;
}
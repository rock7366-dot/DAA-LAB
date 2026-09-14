#include <stdio.h>

int main()
{
    int a[] = {5, 5, 7, 8, 8, 9, 9, 10, 10};
    int n = 9;

    int i, j = 0;

    for (i = 1; i < n; i++)
    {
        if (a[i] != a[j])
        {
            j++;
            a[j] = a[i];
        }
    }

    printf("Array after removing duplicates: ");

    for (i = 0; i <= j; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nNumber of unique elements = %d", j + 1);

    return 0;
}
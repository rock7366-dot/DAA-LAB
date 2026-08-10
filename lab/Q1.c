 // Write a C program to find the second-largest distinct element in an array without sorting it.
 #include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int largest, second;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    second = -999999;

    for (i = 1; i < n; i++) {

        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if (second == -999999)
        printf("No second largest distinct element exists.");
    else
        printf("Second largest distinct element = %d", second);

    return 0;
}
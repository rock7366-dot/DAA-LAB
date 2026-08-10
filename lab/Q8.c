#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

int main() {
    struct Student s[100];
    int n, i, j;
    int topper = 0;
    float classTotal = 0;
    int failed;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input
    for (i = 0; i < n; i++) {

        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Enter marks of 5 subjects:\n");

        s[i].total = 0;

        for (j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;

        // Grade
        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 80)
            s[i].grade = 'B';
        else if (s[i].percentage >= 70)
            s[i].grade = 'C';
        else if (s[i].percentage >= 60)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';

        classTotal += s[i].percentage;
    }

    // Display result
    printf("\n----- STUDENT RESULTS -----\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %d", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    // Find topper
    for (i = 1; i < n; i++) {
        if (s[i].percentage > s[topper].percentage) {
            topper = i;
        }
    }

    printf("\n----- CLASS TOPPER -----\n");
    printf("Roll No: %d\n", s[topper].roll);
    printf("Name: %s\n", s[topper].name);
    printf("Percentage: %.2f\n", s[topper].percentage);

    // Failed students
    printf("\n----- STUDENTS WHO FAILED -----\n");

    for (i = 0; i < n; i++) {
        failed = 0;

        for (j = 0; j < 5; j++) {
            if (s[i].marks[j] < 40) {
                failed = 1;
            }
        }

        if (failed == 1) {
            printf("%d - %s\n", s[i].roll, s[i].name);
        }
    }

    // Class average
    printf("\nClass Average = %.2f\n", classTotal / n);

    return 0;
}
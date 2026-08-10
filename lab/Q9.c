#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int total;
    int available;
};

int main() {
    struct Book books[100];
    int n = 0;
    int choice, id, i, found;

    while (1) {

        printf("\n\n===== LIBRARY MENU =====\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("\nEnter Book ID: ");
            scanf("%d", &books[n].id);

            printf("Enter Title: ");
            scanf(" %[^\n]", books[n].title);

            printf("Enter Author: ");
            scanf(" %[^\n]", books[n].author);

            printf("Enter Total Copies: ");
            scanf("%d", &books[n].total);

            books[n].available = books[n].total;

            n++;

            printf("Book added successfully!\n");
        }

        else if (choice == 2) {

            printf("\nEnter Book ID to search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++) {

                if (books[i].id == id) {

                    printf("\nBook Found!\n");
                    printf("ID: %d\n", books[i].id);
                    printf("Title: %s\n", books[i].title);
                    printf("Author: %s\n", books[i].author);
                    printf("Total Copies: %d\n", books[i].total);
                    printf("Available Copies: %d\n", books[i].available);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Book not found!\n");
        }

        else if (choice == 3) {

            printf("\nEnter Book ID to issue: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++) {

                if (books[i].id == id) {

                    found = 1;

                    if (books[i].available > 0) {
                        books[i].available--;
                        printf("Book issued successfully!\n");
                    }
                    else {
                        printf("Book is currently unavailable!\n");
                    }

                    break;
                }
            }

            if (found == 0)
                printf("Book not found!\n");
        }

        else if (choice == 4) {

            printf("\nEnter Book ID to return: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++) {

                if (books[i].id == id) {

                    found = 1;

                    if (books[i].available < books[i].total) {
                        books[i].available++;
                        printf("Book returned successfully!\n");
                    }
                    else {
                        printf("All copies are already available!\n");
                    }

                    break;
                }
            }

            if (found == 0)
                printf("Book not found!\n");
        }

        else if (choice == 5) {

            printf("\n===== UNAVAILABLE BOOKS =====\n");

            found = 0;

            for (i = 0; i < n; i++) {

                if (books[i].available == 0) {

                    printf("ID: %d\n", books[i].id);
                    printf("Title: %s\n", books[i].title);
                    printf("Author: %s\n\n", books[i].author);

                    found = 1;
                }
            }

            if (found == 0)
                printf("No books are currently unavailable.\n");
        }

        else if (choice == 6) {
            printf("Program ended.\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
// ATM Transaction System 
// • Create a menu-driven program to check balance, deposit money, withdraw money, and exit. 
// • Prevent a withdrawal when the balance is insufficient. 
// • Maintain and display the last five transactions.

#include <stdio.h>

int main() {
    float balance = 1000;
    float amount;
    int choice;
    char transactions[5][50];
    int count = 0;
    int i;

    while (1) {

        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Show Last 5 Transactions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check balance
        if (choice == 1) {
            printf("Current Balance = %.2f\n", balance);
        }

        // Deposit
        else if (choice == 2) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
    

            balance = balance + amount;

            printf("Money deposited successfully.\n");
            printf("New Balance = %.2f\n", balance);

            if (count < 5) {
                sprintf(transactions[count], "Deposited %.2f", amount);
                count++;
            }
            else {
                for (i = 0; i < 4; i++) {
                    sprintf(transactions[i], "%s", transactions[i + 1]);
                }

                sprintf(transactions[4], "Deposited %.2f", amount);
            }
        }

        // Withdraw
        else if (choice == 3) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= balance) {
                balance = balance - amount;

                printf("Money withdrawn successfully.\n");
                printf("New Balance = %.2f\n", balance);

                if (count < 5) {
                    sprintf(transactions[count], "Withdrawn %.2f", amount);
                    count++;
                }
                else {
                    for (i = 0; i < 4; i++) {
                        sprintf(transactions[i], "%s", transactions[i + 1]);
                    }

                    sprintf(transactions[4], "Withdrawn %.2f", amount);
                }
            }
            else {
                printf("Insufficient balance!\n");
            }
        }

        // Show transactions
        else if (choice == 4) {
            printf("\n===== LAST 5 TRANSACTIONS =====\n");

            if (count == 0) {
                printf("No transactions yet.\n");
            }
            else {
                for (i = 0; i < count; i++) {
                    printf("%d. %s\n", i + 1, transactions[i]);
                }
            }
        }

        // Exit
        else if (choice == 5) {
            printf("Thank you for using ATM.\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
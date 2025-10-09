#include <stdio.h>

int main() {
    int choice;
    float balance = 1000.0; // initial balance
    float deposit, withdraw;

    while (1) {
        printf("\n====== ATM MENU ======\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your current balance: ₹%.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &deposit);
                if (deposit > 0) {
                    balance += deposit;
                    printf("₹%.2f deposited successfully!\n", deposit);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &withdraw);
                if (withdraw > balance) {
                    printf("Insufficient balance!\n");
                } else if (withdraw <= 0) {
                    printf("Invalid withdrawal amount.\n");
                } else {
                    balance -= withdraw;
                    printf("₹%.2f withdrawn successfully!\n", withdraw);
                }
                break;

            case 4:
                printf("Thank you for using ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
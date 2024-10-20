#include <stdio.h>

#define NUM_ACCOUNTS 3

// Function to deposit money
void deposit(float accounts[], int account_num, float amount) {
    if (amount > 0) {
        accounts[account_num - 1] += amount;
        printf("Deposited %.2f to account %d. New balance: %.2f\n", amount, account_num, accounts[account_num - 1]);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

// Function to withdraw money
void withdraw(float accounts[], int account_num, float amount) {
    if (amount > accounts[account_num - 1]) {
        printf("Insufficient funds in account %d.\n", account_num);
    } else if (amount > 0) {
        accounts[account_num - 1] -= amount;
        printf("Withdrew %.2f from account %d. New balance: %.2f\n", amount, account_num, accounts[account_num - 1]);
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

// Function to check the balance
void check_balance(float accounts[], int account_num) {
    printf("Current balance in account %d: %.2f\n", account_num, accounts[account_num - 1]);
}

int main() {
    float accounts[NUM_ACCOUNTS] = {0.0, 0.0, 0.0};  // Initialize balances of all 3 accounts to 0
    int choice, account_num;
    float amount;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Thank you for using the banking system.\n");
            break;
        }

        printf("Enter account number (1, 2, or 3): ");
        scanf("%d", &account_num);

        if (account_num < 1 || account_num > NUM_ACCOUNTS) {
            printf("Invalid account number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accounts, account_num, amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accounts, account_num, amount);
                break;
            case 3:
                check_balance(accounts, account_num);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;

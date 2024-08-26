
#include <stdio.h>
#include <conio.h>
#include "atm.h"
#include "balance.c"
#include "createaccount.c"
#include "deposit.c"
#include "menu.c"
#include "password.c"
#include "withdrawal.c"
#include "filehandling.c"
#include "displayaccount.c"
// Define global variables
struct ATM accounts[MAX_ACCOUNTS];
int num_accounts = 0;  // Define num_accounts here

int main() {
    int choice;

    
    password();
load_account();

display_accounts();

  save_account();


    do {
        atm();
        printf("Enter your choice (1-6):\n");

        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                createacc();
                save_account(); // Save account data after creating an account
                break;
            case 2:
                deposit();
                save_account(); // Save account data after depositing money
                break;
            case 3:
                withd();
                save_account(); // Save account data after withdrawing money
                break;
            case 4:
                printf("Enter account number to check balance:\n");
                int acc_num;
                scanf("%d", &acc_num);
                balance(acc_num);
                break;
            case 5:
                display_accounts();  // Display all accounts
                break;
            case 6:
                printf("Thank you for using the ATM machine. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

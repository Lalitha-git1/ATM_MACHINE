#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "atm.h"
#include "balance.c"
#include "createaccount.c"
#include "deposit.c"
#include "menu.c"
#include "password.c"
#include "withdrawl.c"
#include "filehandling.c"

// Define the ATM structure globally
struct ATM A1;

int main() {
    int choice;

    // Load account data from file at the start
    load_account();

    // Ask for password before proceeding
    password();

    do {
        // Display the ATM menu
        atm();
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createacc(); // Create a new account
                save_account(); // Save the account data to file
                break;
            case 2:
                deposit(); // Deposit money
                save_account(); // Save the updated account data to file
                break;
            case 3:
                withd(); // Withdraw money
                save_account(); // Save the updated account data to file
                break;
            case 4:
                balance(); // Check balance
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

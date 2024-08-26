#include <stdio.h>
#include "atm.h"
#include "balance.c"
#include "createaccount.c"
#include "deposit.c"
#include "menu.c"
#include "password.c"
#include "withdrawl.c"
#include "filehandling.c"


// Define the global variable
struct ATM A1;

int main() {
    int choice;


 load_balance();
    password();

    do {
        atm();
        printf("Enter your choice (1-5):\n");

        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                createacc();
                save_account(); // Updated function to save account data
                break;
            case 2:
                deposit();
                save_account(); // Updated function to save account data
                break;
            case 3:
                withd();
                save_account(); // Updated function to save account data
                break;
            case 4:
                balance();
                break;
            case 5:
                printf("Thank you for using the ATM machine. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

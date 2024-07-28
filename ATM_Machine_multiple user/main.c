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
#include "global.c"


void menu();

int main() {
    int choice;
    char ch1, ch2, ch3, ch4;

    loadAccountsFromFile(); // Load account details from file at the start
    loadBalancesFromFile(); // Load balances from file at the start

    printf("Enter the password\n");
    ch1 = getch();
    printf("*");
    ch2 = getch();
    printf("*");
    ch3 = getch();
    printf("*");
    ch4 = getch();
    printf("*");

    if (ch1 == '1' && ch2 == '1' && ch3 == '1' && ch4 == '2') {
        do {
            menu();
            printf("Enter your choice\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    createacc();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withd();
                    break;
                case 4:
                    balance();
                    break;
                case 5:
                    displayaccount();
                    break;
                case 6:
                    saveAccountsToFile(); // Save account details to file before exiting
                    break;
                default:
                    printf("Invalid choice\n");
            }
        } while (choice != 6);
    } else {
        printf("Invalid PIN.....\n");
    }

    return 0;
}
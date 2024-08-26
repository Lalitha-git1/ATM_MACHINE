#include <stdio.h>
#include "atm.h"

void display_accounts() {
    if (num_accounts == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("Displaying all accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Account number: %d\n", accounts[i].accountnumber);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %d\n", accounts[i].amount);
        printf("-----------------------------\n");
    }
}

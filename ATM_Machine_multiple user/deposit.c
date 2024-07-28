#include <stdio.h>
#include "atm.h"

void deposit() {
    int accountnumber, amt, f = 0;
    printf("\nEnter an account number: ");
    scanf("%d", &accountnumber);
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (A1[i].accountnumber == accountnumber) {
            f = 1;
            printf("Name: %s\n", A1[i].name);
            printf("Enter the amount to deposit: ");
            scanf("%d", &amt);
            if (amt < 0) {
                printf("Invalid amount\n");
            } else {
                A1[i].amount += amt;
                saveAccountsToFile(); // Save accounts after deposit
            }
            break;
        }
    }
    if (f == 0) {
        printf("Invalid account number... please check\n");
    }
}

#include <stdio.h>
#include "atm.h"

void createacc() {
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        printf("Enter account number:\n");
        scanf("%d", &A1[i].accountnumber);
        printf("Enter your name:\n");
        scanf("%s", A1[i].name);
        printf("Enter amount:\n");
        scanf("%d", &A1[i].amount);
    }
    saveAccountsToFile(); // Save accounts after creation
}

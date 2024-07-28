#include <stdio.h>
#include "atm.h"

void balance() {
    int accountnumber;
    printf("\nEnter an account number: ");
    scanf("%d", &accountnumber);
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (A1[i].accountnumber == accountnumber) {
            printf("Account Number: %d\n", A1[i].accountnumber);
            printf("Name: %s\n", A1[i].name);
            printf("Balance: %d\n", A1[i].amount);

            // Save the balance of all accounts to balance.txt
            saveAllBalancesToFile();
            break;
        }
    }
}

#include <stdio.h>
#include "atm.h"

void saveAccountsToFile() {
    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        fprintf(file, "%d %s %d\n", A1[i].accountnumber, A1[i].name, A1[i].amount);
    }
    fclose(file);
}

void loadAccountsFromFile() {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("Error opening file! Starting with empty accounts.\n");
        return;
    }
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        fscanf(file, "%d %s %d", &A1[i].accountnumber, A1[i].name, &A1[i].amount);
    }
    fclose(file);
}

void saveAllBalancesToFile() {
    FILE *file = fopen("balance.txt", "w");
    if (file == NULL) {
        printf("Error opening balance file!\n");
        return;
    }
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        fprintf(file, "Account Number: %d, Balance: %d\n", A1[i].accountnumber, A1[i].amount);
    }
    fclose(file);
}

void loadBalancesFromFile() {
    FILE *file = fopen("balance.txt", "r");
    if (file == NULL) {
        printf("Error opening balance file! Starting with empty balances.\n");
        return;
    }
    int accountnumber, balance;
    while (fscanf(file, "Account Number: %d, Balance: %d\n", &accountnumber, &balance) != EOF) {
        for (int i = 0; i < MAX_ACCOUNTS; i++) {
            if (A1[i].accountnumber == accountnumber) {
                A1[i].amount = balance;
                break;
            }
        }
    }
    fclose(file);
}

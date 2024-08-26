#include <stdio.h>
#include "atm.h"

void withd() {
    int accountnumber, amt;
    printf("Enter account number:\n");
    scanf("%d", &accountnumber);

    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].accountnumber == accountnumber) {
            account_index = i;
            break;
        }
    }

    if (account_index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter the amount to withdraw:\n");
    while (scanf("%d", &amt) != 1 || amt < 0) {
        while (getchar() != '\n');
        printf("Invalid amount. Please enter a positive integer:\n");
    }

    if (amt > accounts[account_index].amount) {
        printf("Insufficient funds\n");
    } else {
        accounts[account_index].amount -= amt;
        printf("Withdrawal successful!\n");
    }
}
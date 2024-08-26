#include <stdio.h>
#include "atm.h"

void withd() {
    int amt;
    printf("Enter the amount to withdraw:\n");
    while (scanf("%d", &amt) != 1 || amt < 0) {
        // Clear invalid input
        while (getchar() != '\n');
        printf("Invalid amount. Please enter a positive integer:\n");
    }

    if (amt > A1.amount) {
        printf("Insufficient funds\n");
    } else {
        A1.amount -= amt;
    }
}

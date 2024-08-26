#include <stdio.h>
#include "atm.h"

void deposit() {
    int amt;
    printf("Enter the amount to deposit:\n");
    while (scanf("%d", &amt) != 1 || amt < 0) {
        // Clear invalid input
        while (getchar() != '\n');
        printf("Invalid amount. Please enter a positive integer:\n");
    }
    A1.amount += amt;
}

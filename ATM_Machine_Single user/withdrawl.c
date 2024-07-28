#include <stdio.h>
#include "atm.h"

void withd() {
    int amt;
    printf("Enter the amount to withdraw\n");
    scanf("%d", &amt);

    if (amt < 0) {
        printf("Invalid amount\n");
    } else if (amt > A1.amount) {
        printf("Insufficient funds\n");
    } else {
        A1.amount -= amt;
        print_balance(); // Save the updated balance to a file
    }
}

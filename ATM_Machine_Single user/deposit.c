#include <stdio.h>
#include "atm.h"

void deposit() {
    int amt;
    printf("Enter the amount to deposit\n");
    scanf("%d", &amt);

    if (amt < 0) {
        printf("Invalid amount\n");
    } else {
        A1.amount += amt;
        print_balance(); // Save the updated balance to a file
    }
}

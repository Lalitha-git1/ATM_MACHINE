#include <stdio.h>
#include "atm.h"

void displayaccount() {
    printf("\nAccount Number\tName\tBalance\n");
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        printf("%d\t%s\t%d\n", A1[i].accountnumber, A1[i].name, A1[i].amount);
    }
}

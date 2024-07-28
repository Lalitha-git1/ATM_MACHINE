#include <stdio.h>
#include "atm.h"

// Function to create a new account
void createacc() {
    // Prompt user for account details
    printf("Enter account number:\n");
    scanf("%d", &A1.accountnumber);  // Read account number
    printf("Enter your name:\n");
    scanf("%s", A1.name);  // Read account holder's name
    printf("Enter amount:\n");
    scanf("%d", &A1.amount);  // Read initial deposit amount
    save_account();  // Save the new account details to a file
}

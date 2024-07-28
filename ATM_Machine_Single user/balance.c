#include <stdio.h>
#include "atm.h"

// Function to display the account balance
void balance() {
    // Print the account number, name, and current balance
    printf("Account number: %d\n", A1.accountnumber);
    printf("Name: %s\n", A1.name);
    printf("Balance: %d\n", A1.amount);
    print_balance();  // Save the balance to a text file
}

// Function to print the balance to a file
void print_balance() {
    FILE *file = fopen("balance.txt", "w");  // Open file in text write mode
    if (file == NULL) {
        printf("Error saving balance data.\n");  // Print error if file cannot be opened
        return;
    }
    // Write the account balance data to the file
    fprintf(file, "Account number: %d\n", A1.accountnumber);
    fprintf(file, "Name: %s\n", A1.name);
    fprintf(file, "Balance: %d\n", A1.amount);
    fclose(file);  // Close the file
}

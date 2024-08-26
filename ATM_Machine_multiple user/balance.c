#include <stdio.h>
#include "atm.h"

// Function to display the account balance for a specific account number
void balance(int accountnumber) {
    int found = 0;  // Flag to indicate if account is found

    // Iterate through the accounts array to find the matching account
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].accountnumber == accountnumber) {
            // Account found, display the balance details
            printf("Account number: %d\n", accounts[i].accountnumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %d\n", accounts[i].amount);
            print_balance(i);  // Save the balance to a text file
            found = 1;  // Set found flag to true
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

// Function to print the balance to a file for a specific account index
void print_balance(int index) {
    FILE *file = fopen("balance.txt", "w");  // Open file in text write mode
    if (file == NULL) {
        printf("Error saving balance data.\n");  // Print error if file cannot be opened
        return;
    }

    // Write the account balance data to the file
    fprintf(file, "Account number: %d\n", accounts[index].accountnumber);
    fprintf(file, "Name: %s\n", accounts[index].name);
    fprintf(file, "Balance: %d\n", accounts[index].amount);
    fclose(file);  // Close the file
}

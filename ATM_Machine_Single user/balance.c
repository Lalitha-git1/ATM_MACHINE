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

// Function to load balance from a file
void load_balance() {
    FILE *file = fopen("balance.txt", "r");  // Open file in text read mode
    if (file == NULL) {
        printf("No existing balance data found. Starting with a new account.\n");
        // Initialize default values if the file doesn't exist
        A1.accountnumber = 0;
        snprintf(A1.name, sizeof(A1.name), "Unknown");
        A1.amount = 0;
        return;
    }
    // Read the account balance data from the file
    fscanf(file, "Account number: %d\n", &A1.accountnumber);
    fscanf(file, "Name: %[^\n]\n", A1.name);
    fscanf(file, "Balance: %d\n", &A1.amount);
    fclose(file);  // Close the file
}

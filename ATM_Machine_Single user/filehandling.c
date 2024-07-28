#include <stdio.h>
#include "atm.h"

// Function to save account data to a file
void save_account() {
    FILE *file = fopen("account.txt", "w");  // Open file in text write mode
    if (file == NULL) {
        printf("Error saving account data.\n");  // Print error if file cannot be opened
        return;
    }
    // Write the account data to the file
    fprintf(file, "%d\n%s\n%d\n", A1.accountnumber, A1.name, A1.amount);
    fclose(file);  // Close the file
}

// Function to load account data from a file
void load_account() {
    FILE *file = fopen("account.txt", "r");  // Open file in text read mode
    if (file == NULL) {
        printf("No existing account data found. Create a new account.\n");  // Print message if no file is found
        return;
    }
    // Read the account data from the file
    fscanf(file, "%d\n%s\n%d\n", &A1.accountnumber, A1.name, &A1.amount);
    fclose(file);  // Close the file
}

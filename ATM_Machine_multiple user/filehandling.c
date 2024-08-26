#include <stdio.h>
#include "atm.h"

void save_account() {
    FILE *file = fopen("account.txt", "w");  // Open file in text write mode
    if (file == NULL) {
        printf("Error saving account data.\n");  // Print error if file cannot be opened
        return;
    }

    // Write the number of accounts first
    fprintf(file, "%d\n", num_accounts);
    printf("Saving %d accounts:\n", num_accounts);  // Debug print

    // Write each account's data to the file
    for (int i = 0; i < num_accounts; i++) {
        fprintf(file, "%d\n%s\n%d\n", accounts[i].accountnumber, accounts[i].name, accounts[i].amount);
        printf("Account %d: %d, %s, %d\n", i, accounts[i].accountnumber, accounts[i].name, accounts[i].amount);  // Debug print
    }

    fclose(file);  // Close the file
    printf("Account data saved successfully.\n");
}

void load_account() {
    FILE *file = fopen("account.txt", "r");  // Open file in text read mode
    if (file == NULL) {
        printf("No existing account data found. Starting with a new account list.\n");  // Print message if no file is found
        return;
    }

    // Read the number of accounts
    if (fscanf(file, "%d\n", &num_accounts) != 1) {
        printf("Error reading number of accounts. Starting with a new account list.\n");
        fclose(file);
        num_accounts = 0;  // Ensure we reset num_accounts if there is an error
        return;
    }
    printf("Loaded %d accounts:\n", num_accounts);  // Debug print

    // Check if the number of accounts exceeds the maximum limit
    if (num_accounts > MAX_ACCOUNTS) {
        printf("Error: Number of accounts in file exceeds maximum limit.\n");
        fclose(file);
        num_accounts = 0; // Resetting the number of accounts to 0
        return;
    }

    // Read each account's data from the file
    for (int i = 0; i < num_accounts; i++) {
        if (fscanf(file, "%d\n", &accounts[i].accountnumber) != 1 ||
            fscanf(file, "%49[^\n]\n", accounts[i].name) != 1 ||
            fscanf(file, "%d\n", &accounts[i].amount) != 1) {
            printf("Error reading account data from file. Loading incomplete.\n");
            num_accounts = i;  // Set the number of successfully read accounts
            break;
        }
        printf("Account %d: %d, %s, %d\n", i, accounts[i].accountnumber, accounts[i].name, accounts[i].amount);  // Debug print
    }

    fclose(file);  // Close the file
    printf("Account data loaded successfully.\n");
}

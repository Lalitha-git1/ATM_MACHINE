#include <stdio.h>
#include <stdlib.h>  // Include stdlib.h for atoi
#include <ctype.h>
#include <string.h>
#include "atm.h"

// The global variables are now declared in atm.h
// int num_accounts = 0;  // Removed definition

// Function to check if a string contains only alphabetic characters
int is_alpha(const char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only numeric characters
int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

void createacc() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    struct ATM *new_account = &accounts[num_accounts];
    char buffer[MAX_NAME_LENGTH + 1];
    char amount_buffer[11];  // Buffer for amount input (10 digits + null terminator)

    // Prompt for account number and validate input
    printf("Enter account number:\n");
    while (scanf("%d", &new_account->accountnumber) != 1) {
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid account number (numeric):\n");
    }

    while (getchar() != '\n');

    // Prompt for name and validate input
    printf("Enter your name:\n");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character
            if (is_alpha(buffer)) {
                strncpy(new_account->name, buffer, sizeof(new_account->name) - 1);
                new_account->name[sizeof(new_account->name) - 1] = '\0';  // Ensure null termination
                break;
            } else {
                printf("Invalid input. Please enter a valid name (alphabetic characters only):\n");
            }
        } else {
            printf("Error reading input. Please try again:\n");
        }
    }

    // Prompt for amount and validate input
    printf("Enter amount:\n");
    while (1) {
        if (fgets(amount_buffer, sizeof(amount_buffer), stdin) != NULL) {
            amount_buffer[strcspn(amount_buffer, "\n")] = '\0';  // Remove newline character
            if (is_numeric(amount_buffer)) {
                new_account->amount = atoi(amount_buffer);  // Convert string to integer
                if (new_account->amount < 0) {  // Check for negative value
                    printf("Invalid input. Please enter a valid amount (positive integer):\n");
                } else {
                    break;  // Valid amount entered, break out of the loop
                }
            } else {
                printf("Invalid input. Please enter a valid amount (numeric only):\n");
            }
        } else {
            printf("Error reading input. Please try again:\n");
        }
    }

    num_accounts++;
    printf("Account created successfully!\n");
}

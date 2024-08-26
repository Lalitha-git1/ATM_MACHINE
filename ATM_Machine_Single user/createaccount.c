#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "atm.h"

// Define a constant for the maximum name length
#define MAX_NAME_LENGTH 50

// Function to check if a string contains only alphabetic characters
int is_alpha(const char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            return 0; // Not all characters are alphabetic
        }
        str++;
    }
    return 1; // All characters are alphabetic
}

void createacc() {
    char buffer[MAX_NAME_LENGTH + 1]; // Buffer for name input

    // Prompt for account number and validate input
    printf("Enter account number:\n");
    while (scanf("%d", &A1.accountnumber) != 1) {
        // Clear invalid input
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid account number (numeric):\n");
    }

    // Clear input buffer after valid input
    while (getchar() != '\n');

    // Prompt for name and validate input
    printf("Enter your name:\n");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remove newline character from the end of input
            buffer[strcspn(buffer, "\n")] = '\0';

            if (is_alpha(buffer)) {
                strncpy(A1.name, buffer, sizeof(A1.name) - 1); // Copy validated input to A1.name
                A1.name[sizeof(A1.name) - 1] = '\0'; // Ensure null termination
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
    while (scanf("%d", &A1.amount) != 1 || A1.amount < 0) {
        // Clear invalid input
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid amount (positive integer):\n");
    }

    // Clear input buffer after valid input
    while (getchar() != '\n');
}

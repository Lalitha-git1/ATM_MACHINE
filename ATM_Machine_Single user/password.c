#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "atm.h"

// Function to handle password security
void password() {
    char ch1, ch2, ch3, ch4;  // Variables to hold password characters
    int attempts = 3;  // Number of allowed attempts
    int isPasswordCorrect = 0;  // Flag to check if password is correct

    while (attempts > 0 && !isPasswordCorrect) {
        printf("Enter the password\n");
        ch1 = getch();  // Read first character without echoing
        printf("*");
        ch2 = getch();  // Read second character without echoing
        printf("*");
        ch3 = getch();  // Read third character without echoing
        printf("*");
        ch4 = getch();  // Read fourth character without echoing
        printf("*");

        // Check if the entered password matches the correct password
        if (ch1 == '1' && ch2 == '1' && ch3 == '1' && ch4 == '2') {
            isPasswordCorrect = 1;  // Password is correct
            printf("\nPassword accepted.\n");  // Success message
        } else {
            attempts--;  // Decrement the number of attempts
            printf("\nInvalid PIN..... You have %d attempt(s) remaining.\n", attempts);
            if (attempts == 0) {
                printf("No attempts left. Exiting...\n");
                exit(1);  // Exit the program after 3 failed attempts
            }
        }
        printf("\n");
    }
}

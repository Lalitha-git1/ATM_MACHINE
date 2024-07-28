#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "atm.h"

// Function to handle password security
void password() {
    char ch1, ch2, ch3, ch4;  // Variables to hold password characters

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
    if (ch1 != '1' || ch2 != '1' || ch3 != '1' || ch4 != '2') {
        printf("\nInvalid PIN.....\n");  // Print error for invalid PIN
        exit(1);  // Exit the program
    }
    printf("\n");
}

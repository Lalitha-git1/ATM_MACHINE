#include <stdio.h>
#include <conio.h>
#include "atm.h"

int check_password() {
    char ch1, ch2, ch3, ch4;

    printf("Enter the password\n");
    ch1 = getch();
    printf("*");
    ch2 = getch();
    printf("*");
    ch3 = getch();
    printf("*");
    ch4 = getch();
    printf("*");

    return (ch1 == '1' && ch2 == '1' && ch3 == '1' && ch4 == '2');
}

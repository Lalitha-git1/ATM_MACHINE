#ifndef ATM_H
#define ATM_H

#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNTS 100  // Maximum number of accounts

struct ATM {
    int accountnumber;
    char name[MAX_NAME_LENGTH];
    int amount;
};

// Declare global variables
extern struct ATM accounts[MAX_ACCOUNTS];
extern int num_accounts;  // Declare num_accounts as external

// Function declarations
void atm();
void createacc();
void deposit();
void withd();
void balance(int accountnumber);
void save_account();
void load_account();
void save_balance();
void load_balance();
void print_balance();
void display_accounts();
void display_accounts();  // For displaying all accounts

#endif

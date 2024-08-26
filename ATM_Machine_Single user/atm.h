#ifndef ATM_H
#define ATM_H

struct ATM {
    int accountnumber;
    char name[50];
    int amount;
};

// Declaration of the global variable
extern struct ATM A1;

void atm();
void createacc();
void deposit();
void withd();
void balance();
void save_account();
void load_account();
void save_balance();
void load_balance();
void print_balance();

#endif

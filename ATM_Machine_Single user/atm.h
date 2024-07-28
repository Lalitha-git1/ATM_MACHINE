#ifndef ATM_H
#define ATM_H

struct ATM {
    int accountnumber;
    char name[50];
    int amount;
};

extern struct ATM A1;

void atm();
void createacc();
void deposit();
void withd();
void balance();
void password();
void save_account();
void load_account();
void print_balance(); // Prototype for printing balance to a file

#endif // ATM_H

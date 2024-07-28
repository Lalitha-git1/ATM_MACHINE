#ifndef ATM_H
#define ATM_H

#define MAX_ACCOUNTS 5

struct ATM {
    int accountnumber;
    char name[50];
    int amount;
};

extern struct ATM A1[MAX_ACCOUNTS];

void createacc();
void deposit();
void withd();
void balance();
void displayaccount();
void saveAccountsToFile();
void loadAccountsFromFile();
void saveAllBalancesToFile();
void loadBalancesFromFile();
void menu();

#endif

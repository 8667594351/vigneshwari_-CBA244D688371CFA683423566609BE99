#include <stdio.h>
#include <string.h>

// Define the BankAccount structure
typedef struct {
    char account_number[15];
    char account_holder[100];
    double account_balance;
} BankAccount;

// Function to create a new BankAccount
BankAccount create_account(const char* account_number, const char* account_holder, double initial_balance) {
    BankAccount account;
    strcpy(account.account_number, account_number);
    strcpy(account.account_holder, account_holder);
    account.account_balance = initial_balance;
    return account;
}

// Function to deposit money
void deposit(BankAccount* account, double amount) {
    if (amount > 0) {
        account->account_balance += amount;
        printf("Deposited $%.2lf into the account.\n", amount);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

// Function to withdraw money
void withdraw(BankAccount* account, double amount) {
    if (amount > 0 && amount <= account->account_balance) {
        account->account_balance -= amount;
        printf("Withdrawn $%.2lf from the account.\n", amount);
    } else {
        printf("Invalid withdrawal amount or insufficient balance.\n");
    }
}

// Function to display the account balance
void display_balance(const BankAccount* account) {
    printf("Account Number: %s\n", account->account_number);
    printf("Account Holder: %s\n", account->account_holder);
    printf("Account Balance: $%.2lf\n", account->account_balance);
}

int main() {
    // Create a BankAccount instance
    BankAccount my_account = create_account("12345", "John Doe", 1000.0);

    // Test deposit and withdrawal
    display_balance(&my_account);
    deposit(&my_account, 500.0);
    withdraw(&my_account, 300.0);
    display_balance(&my_account);

    return 0;
}

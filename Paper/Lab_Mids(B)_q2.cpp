#include <iostream>
using namespace std;

// Account class
class Account {
private:
    int accountNumber;
    float balance;

public:
    // Default Constructor
    Account() {
        accountNumber = 0;
        balance = 0.0;
    }

    // Parameterized Constructor
    Account(int accNum, float bal) {
        accountNumber = accNum;
        balance = bal;
    }

    // Destructor
    ~Account() {
        cout << "Account " << accountNumber << " is closed.\n";
    }

    // Deposit method
    void deposit(float amount) {
        balance += amount;
        cout << "Deposited: $" << amount << "\n";
    }

    // Withdraw method with balance check
    void withdraw(float amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    // Display account details
    void display() const {
        cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << "\n";
    }
};

// SavingsAccount class
class SavingsAccount {
private:
    int accountNumber;
    float balance;
    float interestRate;

public:
    // Default Constructor
    SavingsAccount() {
        accountNumber = 0;
        balance = 0.0;
        interestRate = 0.0;
    }

    // Parameterized Constructor
    SavingsAccount(int accNum, float bal, float rate) {
        accountNumber = accNum;
        balance = bal;
        interestRate = rate;
    }

    // Destructor
    ~SavingsAccount() {
        cout << "Savings Account " << accountNumber << " is closed.\n";
    }

    // Apply interest to balance
    void applyInterest() {
        float interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest Added: $" << interest << "\n";
    }

    // Display account details
    void display() const {
        cout << "Savings Account Number: " << accountNumber << "\nBalance: $" << balance
             << "\nInterest Rate: " << interestRate << "%\n";
    }
};

// CheckingAccount class
class CheckingAccount {
private:
    int accountNumber;
    float balance;
    float transactionFee;

public:
    // Default Constructor
    CheckingAccount() {
        accountNumber = 0;
        balance = 0.0;
        transactionFee = 0.0;
    }

    // Parameterized Constructor
    CheckingAccount(int accNum, float bal, float fee) {
        accountNumber = accNum;
        balance = bal;
        transactionFee = fee;
    }

    // Destructor
    ~CheckingAccount() {
        cout << "Checking Account " << accountNumber << " is closed.\n";
    }

    // Withdraw with transaction fee
    void withdraw(float amount) {
        float totalDeduction = amount + transactionFee;
        if (balance >= totalDeduction) {
            balance -= totalDeduction;
            cout << "Withdrawn: $" << amount << " (Fee: $" << transactionFee << ")\n";
        } else {
            cout << "Insufficient balance for withdrawal and fee!\n";
        }
    }

    // Display account details
    void display() const {
        cout << "Checking Account Number: " << accountNumber << "\nBalance: $" << balance
             << "\nTransaction Fee: $" << transactionFee << "\n";
    }
};

// Main function to test the implementation
int main() {
    // Creating and testing Account
    Account acc1(1001, 500.0);
    acc1.deposit(200);
    acc1.withdraw(100);
    acc1.display();
    cout << "\n";

    // Creating and testing SavingsAccount
    SavingsAccount savAcc(2001, 1000.0, 5.0);
    savAcc.applyInterest();
    savAcc.display();
    cout << "\n";

    // Creating and testing CheckingAccount
    CheckingAccount chkAcc(3001, 1500.0, 2.0);
    chkAcc.withdraw(100);
    chkAcc.display();

    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string customerName;
    double balance;

public:

    BankAccount() {
        accountNumber = 0;
        customerName = "";
        balance = 0;
    }

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "Account created successfully!" << endl;
    }

    void depositMoney() {
        double amount;

        cout << "Enter amount to deposit: ";
        cin >> amount;

        balance = balance + amount;

        cout << "Money deposited successfully!" << endl;
        cout << "New Balance: " << balance << endl;
    }
    void withdrawMoney() {
    double amount;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= balance) {
        balance = balance - amount;

        cout << "Money withdrawn successfully!" << endl;
        cout << "New Balance: " << balance << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}
void checkBalance() {
    cout << "\nCurrent Balance: " << balance << endl;
}

    void displayAccount() {
        cout << "\n--- ACCOUNT DETAILS ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: " << balance << endl;

        ofstream file("accounts.txt");

        file << accountNumber << endl;
        file << customerName << endl;
        file << balance << endl;

        file.close();

        cout << "Account details saved to file!" << endl;
    }
};

int main() {
    BankAccount account;

    account.createAccount();
    account.depositMoney();
    account.withdrawMoney();
    account.checkBalance();
    account.displayAccount();

    return 0;
}
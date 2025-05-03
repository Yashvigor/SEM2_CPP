#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum TransactionType { DEPOSIT, WITHDRAW };

struct Transaction {
    TransactionType type;
    double amount;
};

class BankAccount {
protected:
    string accountNumber;
    double balance;
    vector<Transaction> history;

public:
    BankAccount(string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {
        cout << "BankAccount created.\n";
    }

    virtual ~BankAccount() {
        cout << "BankAccount destroyed.\n";
         cout<<"24CE037_Yashvi\n";
    }

    virtual void deposit(double amount) {
        balance += amount;
        history.push_back({DEPOSIT, amount});
        cout << "Deposited: " << amount << ", Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds.\n";
        } else {
            balance -= amount;
            history.push_back({WITHDRAW, amount});
            cout << "Withdrawn: " << amount << ", Balance: " << balance << endl;
        }
    }

    void undoLastTransaction() {
        if (history.empty()) {
            cout << "No transaction to undo.\n";
            return;
        }

        Transaction last = history.back();
        history.pop_back();

        if (last.type == DEPOSIT) {
            balance -= last.amount;
            cout << "Undo deposit of " << last.amount << ", Balance: " << balance << endl;
        } else if (last.type == WITHDRAW) {
            balance += last.amount;
            cout << "Undo withdrawal of " << last.amount << ", Balance: " << balance << endl;
        }
    }

    virtual void display() const {
        cout << "Account: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {
        cout << "SavingsAccount created.\n";
    }

    ~SavingsAccount() {
        cout << "SavingsAccount destroyed.\n";
    }

    void applyInterest() {
        double interest = balance * interestRate;
        deposit(interest);
        cout << "Interest applied: " << interest << endl;
    }

    void display() const override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CurrentAccount : public BankAccount {
    double overdraftLimit;

public:
    CurrentAccount(string accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {
        cout << "CurrentAccount created.\n";
    }

    ~CurrentAccount() {
        cout << "CurrentAccount destroyed.\n";
    }

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Exceeded overdraft limit.\n";
        } else {
            balance -= amount;
            history.push_back({WITHDRAW, amount});
            cout << "Withdrawn: " << amount << ", Balance: " << balance << endl;
        }
    }

    void display() const override {
        BankAccount::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount s("S123",10000, 0.05);
    s.deposit(200);
    s.withdraw(100);
    s.applyInterest();
    s.undoLastTransaction();
    s.display();

    cout << "---------------------\n";

    CurrentAccount c("C456",5000,300);
    c.deposit(150);
    c.withdraw(800);
    c.undoLastTransaction();
    c.display();

    return 0;
}


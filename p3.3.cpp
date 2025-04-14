#include <iostream>
#include <string>
#include <vector>
using namespace std;

class acc_management {
    int acc_no;
    string name;
    double balance;
    static int total_acc;

public:
    // Parameterized constructor
    acc_management(int num, string n, double b) {
        acc_no = num;
        name = n;
        balance = b;
        total_acc++;
    }

    // Default constructor (optional)
    acc_management() {
        acc_no = 0;
        name = "";
        balance = 0.0;
    }

    // Display account info
    void display() const {
        cout << "\nAccount No.: " << acc_no
             << "\nName        : " << name
             << "\nBalance     : " << balance << endl;
    }

    // Friend function to transfer money
    friend void transfer_money(acc_management& from, acc_management& to, double money);

    // Getter for total accounts
    static int get_total_accounts() {
        return total_acc;
    }
};

// Initialize static variable
int acc_management::total_acc = 0;

// Money transfer function
void transfer_money(acc_management& from, acc_management& to, double money) {
    if (money <= 0) {
        cout << "Enter a valid amount to transfer.\n";
    } else if (money > from.balance) {
        cout << "Insufficient balance in source account.\n";
    } else {
        from.balance -= money;
        to.balance += money;
        cout << "Transfer of " << money << " completed successfully.\n";
    }
}

// Main function
int main() {
    vector<acc_management> accounts;

    int n;
    cout << "Enter number of accounts to create: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int acc_no;
        string name;
        double balance;

        cout << "\nEnter details for Account " << i + 1 << ":\n";
        cout << "Account Number: ";
        cin >> acc_no;
        cin.ignore(); // to clear newline from input buffer
        cout << "Account Holder's Name: ";
        getline(cin, name);
        cout << "Initial Balance: ₹";
        cin >> balance;

        acc_management acc(acc_no, name, balance);
        accounts.push_back(acc);
    }

    cout << "\nTotal Accounts Created: " << acc_management::get_total_accounts() << endl;

    // Show all accounts
    cout << "\n--- Account Details ---";
    for (int i = 0; i < accounts.size(); ++i) {
        cout << "\nAccount [" << i << "]";
        accounts[i].display();
    }

    // Example: Transfer money between accounts
    int from_index, to_index;
    double amount;
    cout << "\nEnter index of FROM account (0 to " << n-1 << "): ";
    cin >> from_index;
    cout << "Enter index of TO account (0 to " << n-1 << "): ";
    cin >> to_index;
    cout << "Enter amount to transfer: ₹";
    cin >> amount;

    if (from_index >= 0 && from_index < n && to_index >= 0 && to_index < n) {
        transfer_money(accounts[from_index], accounts[to_index], amount);
    } else {
        cout << "Invalid account indices.\n";
    }

    // Final account states
    cout << "\n--- Updated Account Details ---";
    for (int i = 0; i < accounts.size(); ++i) {
        cout << "\nAccount [" << i << "]";
        accounts[i].display();
    }
    cout << "Yashvi_24CE037";
    return 0;
}

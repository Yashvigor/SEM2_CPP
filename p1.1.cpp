#include<iostream>
using namespace std;

class bankaccount {
    string name;
    double account_number;
    double balance;

public:
    void deposit() {
        int a;
        cout << "\nEnter the amount you want to deposit = ";
        cin >> a;
        balance = balance + a;
    }

    void withdraw() {
        int w;
        cout << "\nEnter the amount you want to withdraw = ";
        cin >> w;
        if (w > balance) {
            cout << "\nInsufficient balance!";
        } else {
            balance = balance - w;
            if (balance == 0)
                cout << "\nThere is no balance left.";
        }
    }

    void display_balance() {
        cout << "\nBalance is = " << balance;
    }

    void getdata()
    {
        cout<<"\nEnter the account holder name = ";
        cin>>name;
        cout<<"\nEnter the account number = ";
        cin>>account_number;
        cout<<"\nEnter the initial balance = ";
        cin>>balance;
    }

    void putdata()
    {
        cout<<"\nThe account holder name = "<< name;
        cout<<"\nThe account number = "<<account_number;
        cout<<"\nThe initial balance = "<<balance;
    }
};

int main() {
    bankaccount b1;
    int choice;

    b1.getdata();

    do {
        cout<<"\n1. Show Account Details";
        cout<<"\n2. Deposit";
        cout<<"\n3. Withdraw";
        cout <<"\n4. Display Balance";
        cout<<"\n5. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                b1.putdata();
                break;
            case 2:
                b1.deposit();
                break;
            case 3:
                b1.withdraw();
                break;
            case 4:
                b1.display_balance();
                break;
            case 5:
                cout<<"\nThank you for using the banking system!";
                break;
            default:
                cout<<"\nInvalid choice. Please try again.";
        }
    }while(choice!=5);

    cout<<"\n24CE037_Yashvi";
    return 0;
}


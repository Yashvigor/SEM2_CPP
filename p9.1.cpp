#include <iostream>
#include <stdexcept>
#include <limits>
#include <iomanip>

using namespace std;

double getValidatedInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value < 0) {
                cout << "Please enter a positive value.\n";
            } else {
                return value;
            }
        } else {
            cout << "Invalid input! Please enter a numeric value.\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
}

int main() {
    try {
        double loanAmount = getValidatedInput("Enter loan amount in rupees: ");
        double income = getValidatedInput("Enter annual income in rupees: ");

        if (income == 0) {
            throw runtime_error("Division by zero! Annual income cannot be zero.");
        }

        double ratio = loanAmount / income;

        cout << fixed << setprecision(2); // Format output to 2 decimal places
        cout << "\nLoan Amount      : " << loanAmount << " rupees\n";
        cout << "Annual Income    : " << income << " rupees\n";
        cout << "Loan-to-Income Ratio: " << ratio << endl;

        if (ratio > 0.4) {
            cout << "Warning: Your loan-to-income ratio is high. Consider reviewing loan terms.\n";
        } else {
            cout << "Good: Your loan-to-income ratio is within a healthy range.\n";
        }

    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << "\n";
    }


    cout<<endl<<"24CE037_Yashvi"<<endl;
    return 0;
}

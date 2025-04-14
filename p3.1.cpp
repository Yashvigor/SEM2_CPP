#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PayrollSystem {
    string emp_name;
    int basic_salary;
    int bonus;

public:
    // Constructor with custom bonus
    PayrollSystem(string name, int salary, int custom_bonus) {
        emp_name = name;
        basic_salary = salary;
        bonus = custom_bonus;
    }

    // Constructor with default bonus
    PayrollSystem(string name, int salary) {
        emp_name = name;
        basic_salary = salary;
        bonus = 1800; // default bonus
    }

    // Inline function to calculate total salary
    inline int total_salary() const {
        return basic_salary + bonus;
    }

    // Display employee details
    void display_data() const {
        cout << "Employee's Name         : " << emp_name << endl;
        cout << "Basic Salary            : ₹" << basic_salary << endl;
        cout << "Bonus                   : ₹" << bonus << endl;
        cout << "Total Salary (Computed) : ₹" << total_salary() << endl;
    }
};

int main() {
    int num;
    vector<PayrollSystem> employees;

    cout << "Enter number of employees: ";
    cin >> num;

    for (int i = 0; i < num; ++i) {
        string name;
        int salary, bonus;
        char hasCustomBonus;


        cin.ignore(); // clear input buffer
        cout << "\nEnter name of employee " << i + 1 << ": ";
        getline(cin, name);

        cout << "Enter basic salary: ₹";
        cin >> salary;

        cout << "Custom bonus? (y/n): ";
        cin >> hasCustomBonus;

        if (hasCustomBonus == 'y' || hasCustomBonus == 'Y') {
            cout << "Enter bonus amount: ₹";
            cin >> bonus;
            PayrollSystem emp(name, salary, bonus);
            employees.push_back(emp);
        } else {
            PayrollSystem emp(name, salary);
            employees.push_back(emp);
        }
    }

    // Display all employee data
    cout << "\n===== Employee Salary Details =====\n";
for (int i = 0; i < employees.size(); ++i) {
    cout << "\nEmployee " << i + 1 << ":";
    employees[i].display_data();
}
    cout << "Yashvi_24CE037";
  return 0;
}//simplify the display data part in this

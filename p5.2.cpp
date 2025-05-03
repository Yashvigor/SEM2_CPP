#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

void stlApproach(int operation) {
    vector<Complex> complexNumbers;
    int n;
    cout << "Enter number of complex numbers: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Complex c;
        cout << "Complex number " << i + 1 << ": " << endl;
        cin >> c;
        complexNumbers.push_back(c);
    }

    Complex result = complexNumbers[0];
    for (int i = 1; i < n; ++i) {
        if (operation == 1)
            result = result + complexNumbers[i];
        else
            result = result - complexNumbers[i];
    }

    cout << (operation == 1 ? "Sum" : "Subtraction result") << " of all complex numbers: ";
    cout << result << endl;
}

void nonStlApproach(int operation) {
    int n;
    cout << "Enter number of complex numbers: ";
    cin >> n;
    Complex* complexNumbers = new Complex[n];

    for (int i = 0; i < n; ++i) {
        cout << "Complex number " << i + 1 << ": " << endl;
        cin >> complexNumbers[i];
    }

    Complex result = complexNumbers[0];
    for (int i = 1; i < n; ++i) {
        if (operation == 1)
            result = result + complexNumbers[i];
        else
            result = result - complexNumbers[i];
    }

    cout << (operation == 1 ? "Sum" : "Subtraction result") << " of all complex numbers: ";
    cout << result << endl;

    delete[] complexNumbers;
}

int main() {
    cout << "Choose approach: 1 for STL, 2 for Non-STL: ";
    int choice;
    cin >> choice;

    cout << "Choose operation: 1 for Addition, 2 for Subtraction: ";
    int operation;
    cin >> operation;

    if ((operation != 1 && operation != 2) || (choice != 1 && choice != 2)) {
        cout << "Invalid choice!" << endl;
    } else {
        if (choice == 1) {
            stlApproach(operation);
        } else {
            nonStlApproach(operation);
        }
    }

    cout << "24CE037_Yashvi";
    return 0;
}

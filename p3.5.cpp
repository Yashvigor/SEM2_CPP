#include <iostream>
using namespace std;

long long superdigit(string n, int k) {
    long long sum = 0;
    for (char digit : n) {
        sum += digit - '0';
    }

    sum *= k;

    while (sum >= 10) {
        long long x = 0;
        while (sum > 0) {
            x += sum % 10;
            sum /= 10;
        }
        sum = x;
    }

    return sum;
}

int main() {
    string x;
    int k;
    cout << "Enter the Number as a String: ";
    cin >> x;
    cout << "Enter the Repetation Factor : ";
    cin >> k;

    cout << "Super Digit: " << superdigit(x, k);
    cout<<endl<<"Yashvi_24CE037";
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseWithStdReverse(vector<int>& sequence) {
    reverse(sequence.begin(), sequence.end());
}

void reverseWithIterators(vector<int>& sequence) {
    auto start = sequence.begin();
    auto end = sequence.end() - 1;
    while (start < end) {
        iter_swap(start, end);
        ++start;
        --end;
    }
}

void printSequence(const vector<int>& sequence) {
    for (int number : sequence) {
        cout << number << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers;
    int input;

    cout << "Enter numbers (enter 0 to stop) :: ";
    while (cin >> input && input != 0) {
        numbers.push_back(input);
    }

    if (numbers.empty()) {
        cout << "No numbers entered.\n";
        return 0;
    }

    cout << "\nReversed using std::reverse:\n";
    vector<int> method1 = numbers;
    reverseWithStdReverse(method1);
    printSequence(method1);

    cout << "\nReversed using manual iterators:\n";
    vector<int> method2 = numbers;
    reverseWithIterators(method2);
    printSequence(method2);


    cout<<endl<<"24CE037_Yashvi"<<endl;
    return 0;
}

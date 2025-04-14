#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate sum of array
int recursiveSum(const vector<int>& arr, int index) {
    // Base case: if index is less than 0, return 0
    if (index < 0)
        return 0;

    // Recursive case: current element + sum of previous elements
    return arr[index] + recursiveSum(arr, index - 1);
}

// Iterative function to calculate sum of array
int iterativeSum(const vector<int>& arr) {
    int sum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    // Use vector for dynamic array
    vector<int> numbers(size);

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Calculate sum using both methods
    int sum_recursive = recursiveSum(numbers, size - 1);
    int sum_iterative = iterativeSum(numbers);

    // Output the results
    cout << "\nSum using recursion: " << sum_recursive << endl;
    cout << "Sum using iteration: " << sum_iterative << endl;
    cout << "24CE037_Yashvi";
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int score;
};

bool compareByScoreDescending(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    vector<Student> students;
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore(); // Clear newline character from the input buffer

    for (int i = 0; i < numStudents; ++i) {
        Student s;
        cout << "Enter full name of student " << i + 1 << ": ";
        getline(cin, s.name);
        cout << "Enter score of " << s.name << ": ";
        cin >> s.score;
        cin.ignore(); // Clear newline character for next getline
        students.push_back(s);
    }

    sort(students.begin(), students.end(), compareByScoreDescending);

    cout << "\nStudent Rankings:\n";
    int rank = 1;
    for (const auto& s : students) {
        cout << "Rank " << rank++ << ": " << s.name << " - " << s.score << " marks\n";
    }


    cout<<endl<<"24CE037_Yashvi"<<endl;
    return 0;
}


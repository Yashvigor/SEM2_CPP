#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    ifstream file("data.txt");
    if (!file) {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    int linecount = 0, wordcount = 0, charcount = 0;

    while (getline(file, line)) {
        lines.push_back(line);
        linecount++;
        charcount += line.length();

        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordcount++;
        }
    }

    file.close();

     cout << "Contents of the file:\n";
    for (const string& l : lines) {
        cout << l << endl;
    }

    cout << "\nStatistics:\n";
    cout << "Total lines: " << linecount << endl;
    cout << "Total words: " << wordcount << endl;
    cout << "Total characters (excluding newlines): " << charcount << endl;
    cout << "24CE037_Yashvi";
    return 0;
}

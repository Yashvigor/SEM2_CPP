#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void displayDirectory(const map<string, vector<string>>& directory) {
    if (directory.empty()) {
        cout << "\nDirectory is empty.\n";
        return;
    }

    cout << "\n=== Directory Structure ===\n";
    for (const auto& pair : directory) {
        const string& folder = pair.first;
        const vector<string>& files = pair.second;

        cout << "Folder: " << folder << "\nFiles:\n";
        if (files.empty()) {
            cout << "  (No files in this folder)\n";
        } else {
            for (const auto& file : files) {
                cout << "  - " << file << "\n";
            }
        }
        cout << endl;
    }
}

int main() {
    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    do {
        cout << "\n1. Add Folder\n2. Add File to Folder\n3. Display Directory\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore(); // To ignore leftover newline after number input

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                getline(cin, folder);  // Allows spaces in folder name
                directory[folder];     // Creates empty folder if not exists
                break;
            case 2:
                cout << "Enter folder name: ";
                getline(cin, folder);
                cout << "Enter file name: ";
                getline(cin, file);
                directory[folder].push_back(file);  // Adds file to folder
                break;
            case 3:
                displayDirectory(directory);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);


    cout<<endl<<"24CE037_Yashvi"<<endl;
    return 0;
}

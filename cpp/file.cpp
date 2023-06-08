#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    string address;
};

void addRecord() {
    ofstream file("students.txt", ios::app);
    
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }
    
    Student student;
    
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cin.ignore(); // Ignore the newline character left by cin
    
    cout << "Enter Name: ";
    getline(cin, student.name);
    
    cout << "Enter Address: ";
    getline(cin, student.address);
    
    file << student.rollNo << ',' << student.name << ',' << student.address << endl;
    
    file.close();
    cout << "Record added successfully." << endl;
}

void displayRecords() {
    ifstream file("students.txt");
    
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }
    
    string line;
    cout << "Roll No\tName\tAddress" << endl;
    
    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        
        int rollNo = stoi(line.substr(0, pos1));
        string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string address = line.substr(pos2 + 1);
        
        cout << rollNo << '\t' << name << '\t' << address << endl;
    }
    
    file.close();
}

int main() {
    int choice;
    
    do {
        cout << "Menu" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        cout << endl;
    } while (choice != 3);
    
    return 0;
}

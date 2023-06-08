#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
    char name[50];
    int rollNo;
    float percentage;

public:
    Student() {}

    Student(const char* _name, int _rollNo, float _percentage) {
        strcpy(name, _name);
        rollNo = _rollNo;
        percentage = _percentage;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Percentage: " << percentage << endl;
        cout << "-----------------------" << endl;
    }

    void writeToFile(fstream& file) {
        file.write(reinterpret_cast<const char*>(this), sizeof(Student));
    }

    void readFromFile(fstream& file, int recordNumber) {
        file.seekg(recordNumber * sizeof(Student), ios::beg);
        file.read(reinterpret_cast<char*>(this), sizeof(Student));
    }

    void updateRecord(fstream& file, int recordNumber) {
        file.seekp(recordNumber * sizeof(Student), ios::beg);
        file.write(reinterpret_cast<const char*>(this), sizeof(Student));
    }

    int getRollNo() const {
        return rollNo;
    }
};

void addStudentData() {
    char name[50];
    int rollNo;
    float percentage;

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cout << "Enter Percentage: ";
    cin >> percentage;

    fstream file("student_data.dat", ios::in | ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    Student student(name, rollNo, percentage);
    student.writeToFile(file);

    cout << "Student data added successfully!" << endl;
    file.close();
}

void displayStudentData() {
    fstream file("student_data.dat", ios::in | ios::binary);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    Student student;
    int recordNumber = 0;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        cout << "Record " << recordNumber + 1 << ":" << endl;
        student.display();
        recordNumber++;
    }

    file.close();
}

void deleteStudentData(int rollNo) {
    fstream file("student_data.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    Student student;
    int recordNumber = 0;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.getRollNo() == rollNo) {
            found = true;
            break;
        }
        recordNumber++;
    }

    if (found) {
        student = Student();
        student.updateRecord(file, recordNumber);
        cout << "Student data deleted successfully!" << endl;
    } else {
        cout << "Student data not found!" << endl;
    }

    file.close();
}

int main() {
    int choice;
    do {
        cout << "************ MENU ************" << endl;
        cout << "1. Add Student Data" << endl;
        cout << "2. Display Student Data" << endl;
        cout << "3. Delete Student Data" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentData();
                break;
            case 2:
                displayStudentData();
                break;
            case 3: {
                int rollNo;
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                deleteStudentData(rollNo);
                break;
            }
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

        cout << "******************************" << endl;
        cout << endl;
    } while (choice != 4);

    return 0;
}

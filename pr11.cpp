#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
    public:
    char name[50];
    int rollNo;
    float percentage;


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

    void writeToFile(ofstream& outFile) {
        outFile.write(reinterpret_cast<const char*>(this), sizeof(Student));
    }

    void readFromFile(ifstream& inFile) {
        inFile.read(reinterpret_cast<char*>(this), sizeof(Student));
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

    ofstream file("student_data.dat", ios::app | ios::binary);
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
    ifstream file("student_data.dat", ios::binary);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    Student student;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if(student.rollNo>0){
        student.display();
        }
    }

    file.close();
}

void deleteStudentData(int rollNo) {
    ifstream inputFile("student_data.dat", ios::binary);
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    ofstream outputFile("temp_data.dat", ios::binary);
    if (!outputFile) {
        cout << "Error creating temporary file." << endl;
        inputFile.close();
        return;
    }

    Student student;
    bool found = false;

    while (inputFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.getRollNo() == rollNo) {
            found = true;
            continue;
        }
        outputFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    inputFile.close();
    outputFile.close();

    remove("student_data.dat");
    rename("temp_data.dat", "student_data.dat");

    if (found) {
        cout << "Student data deleted successfully!" << endl;
    } else {
        cout << "Student data not found!" << endl;
    }
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

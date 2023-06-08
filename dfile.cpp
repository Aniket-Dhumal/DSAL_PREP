#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_RECORDS = 100;

struct Student {
    int rollNumber;
    char name[50];
    char address[100];
};

class StudentDatabase {
private:
    string fileName;

public:
    StudentDatabase(const string& fileName) : fileName(fileName) {}

    int hashFunction(int rollNumber) {
        return rollNumber % MAX_RECORDS;
    }

    void addStudent() {
        ofstream file(fileName, ios::binary | ios::app);

        Student student;
        cout << "Enter Roll Number: ";
        cin >> student.rollNumber;
        cin.ignore(); // Ignore the newline character left by cin

        cout << "Enter Name: ";
        cin.getline(student.name, 50);

        cout << "Enter Address: ";
        cin.getline(student.address, 100);

        int position = hashFunction(student.rollNumber);
        file.seekp(position * sizeof(Student), ios::beg);
        file.write(reinterpret_cast<char*>(&student), sizeof(Student));

        file.close();

        cout << "Student added successfully!" << endl;
    }

    void deleteStudent() {
        int rollNumber;
        cout << "Enter Roll Number of the student to delete: ";
        cin >> rollNumber;

        int position = hashFunction(rollNumber);

        ifstream file(fileName, ios::binary);
        if (!file) {
            cout << "File not found!" << endl;
            return;
        }

        ofstream tempFile("temp.dat", ios::binary);

        Student student;
        while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
            if (student.rollNumber != rollNumber) {
                tempFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
            }
        }

        file.close();
        tempFile.close();

        remove(fileName.c_str());
        rename("temp.dat", fileName.c_str());

        cout << "Student deleted successfully!" << endl;
    }

    void displayStudents() {
        ifstream file(fileName, ios::binary);
        if (!file) {
            cout << "File not found!" << endl;
            return;
        }

        Student student;
        while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Address: " << student.address << endl;
            cout << "---------------------" << endl;
        }

        file.close();
    }

    void run() {
        int choice;

        while (true) {
            cout << "Menu" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Delete Student" << endl;
            cout << "3. Display Students" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    deleteStudent();
                    break;
                case 3:
                    displayStudents();
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice!" << endl;
            }

            cout << endl;
        }
    }
};

int main() {
    string fileName = "students.dat";
    StudentDatabase database(fileName);
    database.run();

    return 0;
}

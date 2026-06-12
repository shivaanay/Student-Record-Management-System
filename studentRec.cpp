#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    public:
    int rollNo;
    string name;
    float cgpa;
};

void addStudent() {
    ofstream file("students.txt", ios::app);
    Student s;

    cout << "Enter Roll No: ";
    cin >> s.rollNo;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter CGPA: ";
    cin >> s.cgpa;

    file << s.rollNo << "\n" << s.name << "\n" << s.cgpa << "\n";
    file.close();

    cout << "Student added successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");
    Student s;
    
    if (!file) {
        cout << "No records found!\n";
        return;
    }
    
    cout << "\n--- Student Records ---\n";
    while (file >> s.rollNo) {
        file.ignore();
        getline(file, s.name);
        file >> s.cgpa;
        cout << "Roll No: " << s.rollNo << "\n";
        cout << "Name: " << s.name << "\n";
        cout << "CGPA: " << s.cgpa << "\n";
        cout << "----------------------\n";
    }
    file.close();
}

void searchStudent() {
    ifstream file("students.txt");
    Student s;
    int searchRoll;
    bool found = false;

    if (!file) {
        cout << "No records found!\n";
        return;
    }

    cout << "Enter Roll No to search: ";
    cin >> searchRoll;

    while (file >> s.rollNo) {
        file.ignore();
        getline(file, s.name);
        file >> s.cgpa;

        if (s.rollNo == searchRoll) {
            cout << "\nStudent Found!\n";
            cout << "Roll No: " << s.rollNo << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "CGPA: " << s.cgpa << "\n";
            found = true;
            break;
        }
    }

    if (!found) cout << "Student not found!\n";
    file.close();
}

void deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    Student s;
    int delRoll;
    bool found = false;

    if (!file) {
        cout << "No records found!\n";
        return;
    }

    cout << "Enter Roll No to delete: ";
    cin >> delRoll;

    while (file >> s.rollNo) {
        file.ignore();
        getline(file, s.name);
        file >> s.cgpa;

        if (s.rollNo == delRoll) {
            found = true;
        } else {
            temp << s.rollNo << "\n" << s.name << "\n" << s.cgpa << "\n";
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) cout << "Student deleted successfully!\n";
    else cout << "Student not found!\n";
}

void updateStudent() {
    fstream file("students.txt", ios::in | ios::out);
    ofstream temp("temp.txt");
    Student s;
    int updateRoll;
    bool found = false;

    if (!file) {
        cout << "No records found!\n";
        return;
    }

    cout << "Enter Roll No to update: ";
    cin >> updateRoll;

    while (file >> s.rollNo) {
        file.ignore();
        getline(file, s.name);
        file >> s.cgpa;

        if (s.rollNo == updateRoll) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter new CGPA: ";
            cin >> s.cgpa;
            found = true;
        }
        temp << s.rollNo << "\n" << s.name << "\n" << s.cgpa << "\n";
    }

    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) cout << "Student updated successfully!\n";
    else cout << "Student not found!\n";
}

int main() {
    int choice;
    
    do {
        cout << "\n--- Student Record Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: cout << "Exiting...\n"; break;
        }
    } while(choice != 6);
    
    return 0;
}
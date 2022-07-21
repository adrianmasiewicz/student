#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "student.hpp"

using namespace std;

void graphicInterface();
void loadData(vector<Student>* ptrStudent);
void addStudent(vector<Student>* ptrStudent);
void autoSave(vector<Student> ptrStudent);
void viewStudents(vector<Student> ptrStudent);
void viewStudent(Student student);
void searchName(vector<Student> ptrStudent);
void searchPesel(vector<Student> ptrStudent);
vector<Student> sortName(vector<Student> students);
vector<Student> sortPesel(vector<Student> students);
vector<Student> removeName(vector<Student> students);
vector<Student> removePesel(vector<Student> students);

int main() {
    int choice;
    vector<Student> vecStudents;

    loadData(&vecStudents);
    system("clear");

    // if (false)
    do {
        cout << "===========================================================\n";
        graphicInterface();

        cout << "\nWhat you want to do: ";
        cin >> choice;

        if (choice == 9)
            system("clear");
        else if (choice == 1)
            addStudent(&vecStudents);
        else if (choice == 2)
            viewStudents(vecStudents);
        else if (choice == 3)
            searchName(vecStudents);
        else if (choice == 4)
            searchPesel(vecStudents);
        else if (choice == 5)
            vecStudents = sortName(vecStudents);
        else if (choice == 6)
            vecStudents = sortPesel(vecStudents);
        else if (choice == 7)
            vecStudents = removeName(vecStudents);
        else if (choice == 8)
            vecStudents = removePesel(vecStudents);

    } while (choice);

    autoSave(vecStudents);
    return 0;
}

void autoSave(vector<Student> ptrStudent) {
    fstream file("../file.txt", ios::out);
    if (file.good()) {
        for (int i = 0; i < ptrStudent.size(); i++) {
            file << ptrStudent[i].getFirstName() << endl;
            file << ptrStudent[i].getName() << endl;
            file << ptrStudent[i].getAddress() << endl;
            file << ptrStudent[i].getIndexNr() << endl;
            file << ptrStudent[i].getPesel() << endl;
            file << ptrStudent[i].getGender() << endl;
            file << "*\n";

            // file.flush();
        }
        file.close();
    }
}

void graphicInterface() {
    // system("clear");
    cout << "1. Add a new student\n";
    cout << "2. View student database\n";
    cout << "3. Search by name\n";
    cout << "4. Search by pesel\n";
    cout << "5. Sort by name\n";
    cout << "6. Sort by pesel\n";
    cout << "7. Remove by name\n";
    cout << "8. Remove by pesel\n";
    cout << "9. Clear interface\n";
    cout << "Any character to save and exit\n";
}

void loadData(vector<Student>* ptrStudent) {
    fstream file;
    string line;
    Student temporaryStudent;
    int i = 0;

    file.open("../file.txt");

    if (file.good() == true) {
        do {
            getline(file, line);

            if (i % 7 == 0) {
                temporaryStudent.setFirstName(line);
            } else if (i % 7 == 1) {
                temporaryStudent.setName(line);
            } else if (i % 7 == 2) {
                temporaryStudent.setAddress(line);
            } else if (i % 7 == 3) {
                temporaryStudent.setIndexNr(line);
            } else if (i % 7 == 4) {
                temporaryStudent.setPesel(line);
            } else if (i % 7 == 5) {
                temporaryStudent.setGender(line[0]);
            } else if (i % 7 == 6) {
                ptrStudent->push_back(temporaryStudent);
            }
        } while (++i && !file.eof());
    } else
        cout << "Error file!\n";
}

void addStudent(vector<Student>* ptrStudent) {
    string firstName;
    string name;
    string address;
    string indexNr;
    string pesel;
    int nS = ptrStudent->size();
    char gender;
    static string temporary_id = "A0000";
    temporary_id[4] += nS;
    indexNr = temporary_id;

    cout << "Enter a first name: ";
    cin >> firstName;
    cout << "Enter a name: ";
    cin >> name;
    cout << "Enter a address: ";
    cin >> address;
    do {
        cout << "Enter a nr PESEL: ";
        cin >> pesel;
        if (pesel.size() != 11) {
            cout << "Incorrect data (11 digits). ";
        }
    } while (pesel.size() != 11);

    cout << "Enter a gender (m - man, f - female, o - other): ";
    cin >> gender;

    Student student(firstName, name, address, indexNr, pesel, gender);
    ptrStudent->push_back(student);
}

void viewStudents(vector<Student> ptrStudent) {
    for (int i = 0; i < ptrStudent.size(); i++) {
        viewStudent(ptrStudent[i]);
    }
}

void viewStudent(Student s1) {
    cout << "INDEX: " << s1.getIndexNr() << " | ";
    cout << "First name: " << s1.getFirstName() << " | ";
    cout << "Name: " << s1.getName() << " | ";
    cout << "Address: " << s1.getAddress() << " | ";
    cout << "PESEL: " << s1.getPesel() << " | ";
    cout << "Sex: " << s1.getGender() << " |\n";
}

void searchName(vector<Student> ptrStudent) {
    string name;

    cout << "Enter a Name Student: ";
    cin >> name;

    for (auto el : ptrStudent) {
        if (name == el.getName()) {
            cout << "INDEX: " << el.getIndexNr() << " | ";
            cout << "First name: " << el.getFirstName() << " | ";
            cout << "Name: " << el.getName() << " | ";
            cout << "Address: " << el.getAddress() << " | ";
            cout << "PESEL: " << el.getPesel() << " | ";
            cout << "Sex: " << el.getGender() << " |\n";
        }
    }
}

void searchPesel(vector<Student> ptrStudent) {
    string pesel;

    cout << "Enter a pesel student: ";
    cin >> pesel;

    for (auto el : ptrStudent) {
        if (pesel == el.getPesel()) {
            cout << "INDEX: " << el.getIndexNr() << " | ";
            cout << "First name: " << el.getFirstName() << " | ";
            cout << "Name: " << el.getName() << " | ";
            cout << "Address: " << el.getAddress() << " | ";
            cout << "PESEL: " << el.getPesel() << " | ";
            cout << "Sex: " << el.getGender() << " |\n";
        }
    }
}

vector<Student> sortName(vector<Student> students) {
    vector<Student> temporaryStudents;
    int nrStudentDelete;
    Student s1;

    int kEnd = students.size();
    for (int k = 0; k < kEnd; k++) {
        s1 = students[0];
        nrStudentDelete = 0;
        for (int i = 1; i < students.size(); i++) {
            for (int j = 0; j < (students[i].getName()).size(); j++) {
                if ((s1.getName())[j] < (students[i].getName())[j]) {
                    break;
                } else if ((s1.getName())[j] == (students[i].getName())[j]) {
                    continue;
                } else {
                    s1 = students[i];
                    nrStudentDelete = i;
                    break;
                }
            }
        }
        temporaryStudents.push_back(s1);
        students.erase(students.begin() + nrStudentDelete, students.begin() + nrStudentDelete + 1);
    }
    viewStudents(temporaryStudents);
    return temporaryStudents;
}

vector<Student> sortPesel(vector<Student> students) {
    vector<Student> temporaryStudents;
    int nrStudentDelete;
    Student s1;

    int kEnd = students.size();
    for (int k = 0; k < kEnd; k++) {
        s1 = students[0];
        nrStudentDelete = 0;
        for (int i = 1; i < students.size(); i++) {
            for (int j = 0; j < (students[i].getPesel()).size(); j++) {
                if ((s1.getPesel())[j] < (students[i].getPesel())[j]) {
                    break;
                } else if ((s1.getPesel())[j] == (students[i].getPesel())[j]) {
                    continue;
                } else {
                    s1 = students[i];
                    nrStudentDelete = i;
                    break;
                }
            }
        }
        temporaryStudents.push_back(s1);
        students.erase(students.begin() + nrStudentDelete, students.begin() + nrStudentDelete + 1);
    }
    viewStudents(temporaryStudents);
    return temporaryStudents;
}

vector<Student> removeName(vector<Student> students) {
    string sNameRemove;
    int iNameRemove;
    int howMuch = 0;

    cout << "Enter the name of the student you want to remove: ";
    cin >> sNameRemove;

    for (int i = 0; i < students.size(); i++) {
        if (sNameRemove == students[i].getName()) {
            cout << i << " : ";
            viewStudent(students[i]);
            howMuch++;
            iNameRemove = i;
        }
    }

    if (howMuch == 0) {
        cout << "No such student was found\n";
    } else if (howMuch == 1) {
        students.erase(students.begin() + iNameRemove, students.begin() + iNameRemove + 1);
        cout << "Student removed\n";
    } else if (howMuch > 1) {
        cout << "Enter the student number: ";
        cin >> iNameRemove;
        students.erase(students.begin() + iNameRemove, students.begin() + iNameRemove + 1);
        cout << "Student removed\n";
    }
    return students;
}

vector<Student> removePesel(vector<Student> students) {
    string sPeselRemove;
    int iPeselRemove;
    int howMuch = 0;

    cout << "Enter the Pesel of the student you want to remove: ";
    cin >> sPeselRemove;

    for (int i = 0; i < students.size(); i++) {
        if (sPeselRemove == students[i].getPesel()) {
            cout << i << " : ";
            viewStudent(students[i]);
            howMuch++;
            iPeselRemove = i;
        }
    }

    if (howMuch == 0) {
        cout << "No such student was found\n";
    } else if (howMuch == 1) {
        students.erase(students.begin() + iPeselRemove, students.begin() + iPeselRemove + 1);
        cout << "Student removed\n";
    } else if (howMuch > 1) {
        cout << "Enter the student number: ";
        cin >> iPeselRemove;
        students.erase(students.begin() + iPeselRemove, students.begin() + iPeselRemove + 1);
        cout << "Student removed\n";
    }
    return students;
}
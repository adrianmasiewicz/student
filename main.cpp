#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "student.hpp"

using namespace std;

void graphicInterface();
void loadData(vector<Student>* ptrStudent);
void addStudent(vector<Student>* ptrStudent);
void viewStudents(vector<Student> ptrStudent);
void searchName(vector<Student> ptrStudent);
void searchPesel(vector<Student> ptrStudent);
void sortName(vector<Student> ptrStudent);
void sortPesel(vector<Student> ptrStudent);

int main() {
    int choice;
    vector<Student> vecStudents;

    loadData(&vecStudents);

    do {
        graphicInterface();

        cout << "\nWhat you want to do: ";
        cin >> choice;
        system("clear");

        if (choice == 1)
            addStudent(&vecStudents);
        else if (choice == 2)
            viewStudents(vecStudents);

    } while (choice);

    return 0;
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
    cout << "q - exit\n";
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
                std::string str = line;
                int iLine = atoi(str.c_str());
                temporaryStudent.setPesel(iLine);
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
    int pesel;
    char gender;

    static string temporary_id = "A0000";
    temporary_id[4]++;
    indexNr = temporary_id;

    cout << "Enter a first name: ";
    cin >> firstName;
    cout << "Enter a name: ";
    cin >> name;
    cout << "Enter a address: ";
    getline(cin, address);
    cout << "Enter a nr PESEL: ";
    cin >> pesel;
    cout << "Enter a gender (m - man, f - female, o - other): ";
    cin >> gender;

    Student student(firstName, name, address, indexNr, pesel, gender);
    ptrStudent[0].push_back(student);
}

void viewStudents(vector<Student> ptrStudent) {
    for (int i = 0; i < ptrStudent.size(); i++) {
        cout << ptrStudent[i].getIndexNr() << endl;
        cout << "First name: " << ptrStudent[i].getFirstName() << endl;
        cout << "Name: " << ptrStudent[i].getName() << endl;
        cout << "Address: " << ptrStudent[i].getAddress() << endl;
        cout << "PESEL: " << ptrStudent[i].getPesel() << endl;
        cout << "Sex: " << ptrStudent[i].getGender() << endl;
        cout << "================================================\n";
    }
}

void searchName(vector<Student> ptrStudent) {
}
void searchPesel(vector<Student> ptrStudent) {
}
void sortName(vector<Student> ptrStudent) {
}
void sortPesel(vector<Student> ptrStudent) {
}
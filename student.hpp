#pragma once
#include <string>

using namespace std;

class Student {
    string firstName_;
    string name_;
    string address_;
    string indexNr_;
    int pesel_;
    char gender_;

public:
    Student();
    Student(string firstName, string name);
    Student(string firstName, string name, string address, string indexNr, int pesel, char gender);
    ~Student();

    string getFirstName() const;
    string getName() const;
    string getAddress() const;
    string getIndexNr() const;
    int getPesel() const;
    char getGender() const;

    void setFirstName(const string& firstName);
    void setName(const string& name);
    void setAddress(const string& address);
    void setIndexNr(const string& indexNr);
    void setPesel(const int pesel);
    void setGender(const char& gender);
};
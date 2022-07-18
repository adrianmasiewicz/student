#include "student.hpp"
#include <iostream>

Student::Student()
    : firstName_("No data"),
      name_("No data"),
      address_("No data"),
      indexNr_("No data"),
      pesel_(-1),
      gender_('-') {}

Student::Student(string firstName, string name)
    : firstName_(firstName),
      name_(name),
      address_("No data"),
      indexNr_("No data"),
      pesel_(-1),
      gender_('-') {}

Student::Student(string firstName, string name, string address, string indexNr, int pesel, char gender)
    : firstName_(firstName),
      name_(name),
      address_(address),
      indexNr_(indexNr),
      pesel_(pesel),
      gender_(gender) {}

Student::~Student() {}

string Student::getFirstName() const {
    return firstName_;
}

string Student::getName() const {
    return name_;
}

string Student::getAddress() const {
    return address_;
}

string Student::getIndexNr() const {
    return indexNr_;
}

int Student::getPesel() const {
    return pesel_;
}

char Student::getGender() const {
    return gender_;
}

void Student::setFirstName(const string& firstName) {
    firstName_ = firstName;
}

void Student::setName(const string& name) {
    name_ = name;
}
void Student::setAddress(const string& address) {
    address_ = address;
}
void Student::setIndexNr(const string& indexNr) {
    indexNr_ = indexNr;
}
void Student::setPesel(const int pesel) {
    pesel_ = pesel;
}
void Student::setGender(const char& gender) {
    gender_ = gender;
}
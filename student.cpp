#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

Student::Student() {
  // Initialize variables in the constructor
  strcpy(firstName, "");
  strcpy(lastName, "");
  studentID = 0;
  GPA = 0.0;
}

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}

int Student::getID() {
  return studentID;
}

float Student::getGPA() {
  return GPA;
}

void Student::setID(int newID) {
  studentID = newID;
}

void Student::setGPA(float newGPA) {
  GPA = newGPA;
}

void Student::print() {
  cout << firstName << " " << lastName << endl;
}

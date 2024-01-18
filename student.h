#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {

public:
  // Functions for Student class
  Student();
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  void setID(int newID);
  void setGPA(float newGPA);
  void print();  // Added print function

private:
  // All variables are private
  char firstName[81];
  char lastName[81];
  int studentID;
  float GPA;
};

#endif


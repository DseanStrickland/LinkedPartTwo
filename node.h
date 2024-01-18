#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"

using namespace std;

class Node {
public:
  // constructor (and the student assigned to the node)
  Node(Student* newStudent);

  // destructor
  ~Node();

  // get the next node in the list
  Node* getNext();

  // get the student that is assigned to the node
  Student* getStudent();

  // set the next node in the list
  void setNext(Node* n);

private:
  // Variables
  Node* next;
  Student* stu;
};

#endif

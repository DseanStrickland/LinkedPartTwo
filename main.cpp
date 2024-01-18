#include<iostream>
#include<vector>
#include <iomanip>
#include "node.h"
#include "student.h"
using namespace std;

// Function Declarations
void AVERAGE(Node* head, float sum, int total);
void ADD(Node* &head, Node* curr, Node* prev, Node* inputNode);
void PRINT(Node* next);
void DELETE (Node* &head,Node* prev, Node* current, int ID);

int main() {
  char command[81];
  bool running = true;
  Node* head = nullptr; // Fixing the capitalization
    
  cout << "Welcome to StudentList (LinkedList)" << endl;

  while (running == true) {
    cout << "Enter one of the following: ADD, PRINT, DELETE, AVERAGE, or QUIT." << endl;
    cout << "ADD to add a student." << endl;
    cout << "PRINT to print all student." << endl;
    cout << "AVERAGE to return an average of all student's GPA" << endl;
    cout << "DELETE to delete a student." << endl;
    cout << "QUIT to quit the program." << endl;
    
    cin.get(command, 80);
    cin.ignore(80, '\n');
    
    if (strcmp(command, "ADD") == 0) {
      Student* inputStudent = new Student();
      
      cout << "First Name: " << endl;
      char input[20];
      cin.get(input, 20);
      cin.ignore(80, '\n');  // Added to consume the newline character
      strcpy(inputStudent->getFirstName(), input);
      
      cout << "Last Name: " << endl;
      cin.get(input, 20);
      cin.ignore(80, '\n');  // Added to consume the newline character
      strcpy(inputStudent->getLastName(), input);
      
      cout << "Student ID: " << endl;
      int int1;
      cin >> int1;
      cin.ignore(80, '\n');  // Added to consume the newline character
      inputStudent->setID(int1);
      
      cout << "Student GPA: " << endl;
      float float1;
      cin >> float1;
      cin.ignore(80, '\n');  // Added to consume the newline character
      inputStudent->setGPA(float1);

      Node* inputNode = new Node(inputStudent);
      
      ADD(head, head, head, inputNode);
    }
    
    else if (strcmp(command, "PRINT") == 0) {
      cout << "Printing the Student List: " << endl;
      PRINT(head);
    }
    
    else if (strcmp(command, "DELETE") == 0) {
        int ID = 0;
        cout << "Please enter the student id of the student that you want to delete" << endl;
        cin >> ID;
        cin.ignore(11, '\n');
        
        DELETE(head, head, head, ID);
    }
    
    else if (strcmp(command, "AVERAGE") == 0) {
      float sum = 0;
      int total = 0;
      AVERAGE(head, sum, total);
    }
    
    else if (strcmp(command, "QUIT") == 0) {
      cout << "Quitting program... " << endl;
      running = false;
    }
    
    else {
      cout << "Try again" << endl;
    }
  }
}

// Function Definitions
void ADD(Node* &head, Node* curr, Node* prev, Node* inputNode) {
  if (head == nullptr) {
    head = inputNode;
  }
  else {
    if (inputNode->getStudent()->getID() < head->getStudent()->getID()) {
      Node* tempNode = head;
      head = inputNode;
      head->setNext(tempNode);
    }
    else if (inputNode->getStudent()->getID() < curr->getStudent()->getID()) {
      prev->setNext(inputNode);
      inputNode->setNext(curr);
    }
    else if (curr->getNext() == nullptr) {
      curr->setNext(inputNode);
    }
    else {
      ADD(head, curr->getNext(), curr, inputNode);
    }
    return;
  }
  return;
}

void PRINT(Node* next) {
  if (next != nullptr) {
    cout << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << endl;
    PRINT(next->getNext());
  }
}

void DELETE(Node* &head, Node* prev, Node* current, int ID) {
    if (head == nullptr) {
        cout << "No Students" << endl;
        return;
    }

    if (ID == current->getStudent()->getID()) {
        if (current == head) {
            head = head->getNext();
            delete current;
        } else {
            prev->setNext(current->getNext());
            delete current;
        }
        cout << "Student with ID " << ID << " deleted successfully." << endl;
        return;
    }

    if (current->getNext() != nullptr) {
        DELETE(head, current, current->getNext(), ID);
    } else {
        cout << "Student with ID " << ID << " not found." << endl;
    }
}

void AVERAGE(Node* head, float sum, int total) {
  if (head == nullptr && total == 0) {
    cout << "No students" << endl;
  }
  else if (head != nullptr) {
    sum += head->getStudent()->getGPA();
    total++;
    AVERAGE(head->getNext(), sum, total);
  }
  else {
    cout << "Average GPA: ";
    cout << fixed << setprecision(2) << (sum / total) << endl;
  }
}

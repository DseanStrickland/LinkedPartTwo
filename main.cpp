//Arjun Pai
//Linked List Part II
// Studentlist but using linked lists and nodes
// Shoutout to Jazveer Kaler and Tejas Pandit for help debugging


#include<iostream>
#include<vector>
#include <iomanip>
#include "node.h"
#include "student.h"
using namespace std;

// Function Initilization
void AVERAGE(Node* head, float sum, int total);
void ADD(Node* &head, Node* curr, Node* prev, Node* inputNode);
void PRINT(Node* next);
void DELETE (Node* &head,Node* prev, Node* current, int ID);

int main() {
  char command[81];
  bool running = true;
  Node* head = nullptr; 
    
  cout << "Welcome to StudentList (LinkedList)" << endl;

  //Starts the program
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
      //Takes in information
      cout << "First Name: " << endl;
      char input[20];
      cin.get(input, 20);
      cin.ignore(80, '\n');  
      strcpy(inputStudent->getFirstName(), input);
      
      cout << "Last Name: " << endl;
      cin.get(input, 20);
      cin.ignore(80, '\n');  
      strcpy(inputStudent->getLastName(), input);
      
      cout << "Student ID: " << endl;
      int int1;
      cin >> int1;
      cin.ignore(80, '\n');  
      inputStudent->setID(int1);
      
      cout << "Student GPA: " << endl;
      float float1;
      cin >> float1;
      cin.ignore(80, '\n');  
      inputStudent->setGPA(float1);

      Node* inputNode = new Node(inputStudent);
      
      ADD(head, head, head, inputNode); //runs add function
    }

      //print
    else if (strcmp(command, "PRINT") == 0) {
      cout << "Printing the Student List: " << endl;
      PRINT(head);
    }

      
    else if (strcmp(command, "DELETE") == 0) { //funciton keeps crashing no idea whats going on
        int ID = 0;
        cout << "Please enter the student id of the student that you want to delete" << endl;
        cin >> ID;
        cin.ignore(11, '\n'); //was missing this line 
        
        DELETE(head, head, head, ID);
      // cout << "testing" << ID << endl;
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

// Add Function
//NOTE: Every single function has a case where if the list is empty
void ADD(Node* &head, Node* curr, Node* prev, Node* inputNode) {
  if (head == nullptr) {
    head = inputNode;
  }

    //inserts based on ID
  else {
    if (inputNode->getStudent()->getID() < head->getStudent()->getID()) {
      Node* tempNode = head;
      head = inputNode;
      head->setNext(tempNode);
    }
      //Something not working here
    else if (inputNode->getStudent()->getID() < curr->getStudent()->getID()) {
      prev->setNext(inputNode);
      inputNode->setNext(curr);
    }
      //end of list
    else if (curr->getNext() == nullptr) {
      curr->setNext(inputNode);
    }
    else {
      ADD(head, curr->getNext(), curr, inputNode); //Recursive
    }
    return;
  }
  return;
}

// print
void PRINT(Node* next) {
  if (next != nullptr) {
    cout << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << endl;
    PRINT(next->getNext());
  }
}

//
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
      //checks if there are any many more nodes in the list
    if (current->getNext() != nullptr) {
        DELETE(head, current, current->getNext(), ID);
    } else {
        cout << "Student with ID " << ID << " not found." << endl;
    }
}

//Average
void AVERAGE(Node* head, float sum, int total) {
  if (head == nullptr && total == 0) {
    cout << "No students" << endl;
  }
  else if (head != nullptr) {
    sum += head->getStudent()->getGPA();
    total++;
    AVERAGE(head->getNext(), sum, total); //using recursion to iterate through the list and add gpa to total
  }
  //returns average
  else {
    cout << "Average GPA: ";
    cout << fixed << setprecision(2) << (sum / total) << endl;
  }
}

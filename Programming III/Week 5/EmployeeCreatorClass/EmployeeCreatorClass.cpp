// Filename: EmployeeCreatorClass.cpp
// Author: Joshua Porter
// Description: Employee class that stores variables for an employee, ID, department, and position, then displays the information.
// Date: 02-09-2024

/* Pseudocode
* 
	Define Employee Class
		Initialize member variables
			name, department, position (strings)
			idNumber (interger)
	Constructors
		Full constructor that accepts and assigns member variables
        Partial constructor that accepts name and idNumber : sets department and position to empty strings
        default constructor assigns empty strings to all member variables
    Mutators (set____)
    Accessors (get____)
    displayEmployeeInfo function to print in neat formatting.

    int main()
    Create Employee objects with member parameters
    call employee.displayEmployeeInfo for each employee
*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string department;
    string position;
    int idNumber;

public:
    // Constructor that accepts name, idNumber, department, and position
    Employee(string empName, int empIdNumber, string empDepartment, string empPosition) {
        name = empName;
        idNumber = empIdNumber;
        department = empDepartment;
        position = empPosition;
    }

    // Constructor that accepts name and idNumber, sets department and position to empty strings
    Employee(string empName, int empIdNumber) {
        name = empName;
        idNumber = empIdNumber;
        department = "";
        position = "";
    }

    // Default constructor that initializes member variables to defaults
    Employee() {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }

    // Mutators
    void setName(string newName) { name = newName; }
    void setIdNumber(int newIdNumber) { idNumber = newIdNumber; }
    void setDepartment(string newDepartment) { department = newDepartment; }
    void setPosition(string newPosition) { position = newPosition; }

    // Accessors
    string getName() const { return name; }
    int getIdNumber() const { return idNumber; }
    string getDepartment() const { return department; }
    string getPosition() const { return position; }

    // Function to display employee information
    void displayEmployeeInfo() {
        cout << "Name: " << name << "\nID Number: " << idNumber
            << "\nDepartment: " << department << "\nPosition: " << position << endl << endl;
    }
};

int main() {
    // Creating Employee objects
    Employee employee1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee employee2("Mark Jones", 39119, "IT", "Programmer");
    Employee employee3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    // Displaying the data for each employee
    cout << "Employee Information \n\n";
    employee1.displayEmployeeInfo();
    employee2.displayEmployeeInfo();
    employee3.displayEmployeeInfo();

    return 0;
}
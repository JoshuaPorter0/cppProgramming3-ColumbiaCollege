// Filename: PayrollProgram.cpp
// Author: Joshua Porter
// Description: Creates a class for employee's payroll, the main program prompts the user for relevant information, and displays information.
// Date: 02-29-2024

/* Pseudocode:
 Class Payroll
    Private:
        hourlyRate as Float
        hoursWorked as Float
        totalPay as Float
    Public:
        Function SetHoursWorked(hours as Float)
        Function CalculatePay()
        Function GetTotalPay() as Float
End Class

Main Program
    Declare payrollArray[7] as Payroll
    For each employee in payrollArray
        Prompt for hours worked
        If hours <= 60 Then
            Set hours worked for employee
            Calculate pay for employee
        Else
            Display error message
    Next
    Display all employees' total pay
End Program
*/

#include <iostream>
#include <iomanip> // For std::setprecision

using namespace std;

class Payroll {
private:
    float hourlyRate; // Using float for this simple program will help in memory conservation
    float hoursWorked;
    float totalPay;

public:
    Payroll() : hourlyRate(25.0), hoursWorked(0), totalPay(0) {} // Assuming a default hourly rate

    void SetHoursWorked(float hours) {
        if (hours > 60) {
            cout << "Error: Hours worked cannot exceed 60." << endl;
            return;
        }
        hoursWorked = hours;
    }

    void CalculatePay() {
        totalPay = hourlyRate * hoursWorked;
    }

    float GetTotalPay() const {
        return totalPay;
    }
};

int main() {
    Payroll payrollArray[7]; // Array of 7 payroll objects

    // Input hours worked for each employee, providing input validition for hours >60
    for (int i = 0; i < 7; ++i) {
        float hours;
        do {
            cout << "Enter the number of hours worked by employee #" << (i + 1) << " (0-60): ";
            cin >> hours;
            if (hours < 0 || hours > 60) {
                cout << "Invalid input. Please enter a value between 0 and 60." << endl;
            }
            else {
                payrollArray[i].SetHoursWorked(hours);
                payrollArray[i].CalculatePay();
                break; // Exit the loop after valid input
            }
        } while (true); // Keep asking until valid input is provided
    }

    // Display total pay for each employee
    cout << fixed << setprecision(2); // Format output for currency
    cout << "\nGross Pay for Each Employee:" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << "Employee #" << (i + 1) << ": $";
        cout << payrollArray[i].GetTotalPay() << endl;
    }

    return 0;
}

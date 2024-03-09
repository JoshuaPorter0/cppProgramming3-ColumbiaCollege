// Filename: TestClass.cpp
// Author: Joshua Porter
// Description: Creates a class for 3 tests and tests it with a program that takes 3 user inputs for test score and displays the average.
// Date: 02-29-2024

/* Pseudocode
Function Template total
    Input: numValues
    Process: Accumulate total of numValues entered by user
    Output: Return accumulated total

Main Program
    Test total function with various types (int, float, double)
    Display results
End Program
*/

#include <iostream>
using namespace std;

// Function template to accumulate total
template <typename T>
T total(int numValues) {
    T value, sum = 0; // Initialize sum and value to zero
    for (int i = 0; i < numValues; ++i) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> value; // Read a value of type T
        sum += value; // Accumulate the total
    }
    return sum; // Return the accumulated total
}

int main() {
    // Test with int
    cout << "Enter 3 integers:" << endl;
    int intTotal = total<int>(3); // Read and total 3 integers
    cout << "Total (int): " << intTotal << "\n\n";

    // Test with float
    cout << "Enter 3 floats:" << endl;
    float floatTotal = total<float>(3); // Read and total 3 floats
    cout << "Total (float): " << floatTotal << "\n\n";

    // Test with double
    cout << "Enter 3 doubles:" << endl;
    double doubleTotal = total<double>(3); // Read and total 3 doubles
    cout << "Total (double): " << doubleTotal << "\n";

    return 0;
}

// Filename: AbsoluteValue.cpp
// Author: Joshua Porter
// Description: Uses a template to change any data type's value into its absolute value
// Date: 02-16-2024

#include <iostream>
using namespace std;

// Template function to calculate the absolute value of a number
template <typename T>
T absoluteValue(T x) {
    return (x < 0) ? -x : x;  //if x is less than 0, then negate the negative, if it is positive return x.
}

// Driver program to demonstrate the use of the absoluteValue template
int main() {
    // Test with an integer
    int intVal = -5;
    int intVal2 = 68;
    cout << "The absolute value of " << intVal << " is " << absoluteValue(intVal) << endl;
    cout << "The absolute value of " << intVal2 << " is " << absoluteValue(intVal2) << endl;

    // Test with a floating-point number
    float floatVal = -76.5;
    cout << "The absolute value of " << floatVal << " is " << absoluteValue(floatVal) << endl;
    float floatVal2 = 81.9;
    cout << "The absolute value of " << floatVal2 << " is " << absoluteValue(floatVal2) << endl;

    // Test with a double
    double doubleVal = 123.456;
    cout << "The absolute value of " << doubleVal << " is " << absoluteValue(doubleVal) << endl;
    double doubleVal2 = -123.456;
    cout << "The absolute value of " << doubleVal2 << " is " << absoluteValue(doubleVal2) << endl;

    return 0;
}

// Filename: templatesMinMaxx.cpp
// Author: Joshua Porter
// Description: Takes arguements of different data types into a function template and demonstrates it in the main driver program.
// Date: 02-16-2024

#include <iostream>
using namespace std;

// Template function for finding the minimum of two values
template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}

// Template function for finding the maximum of two values
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Driver program to demonstrate the use of minimum and maximum templates
int main() {
    // Test with integers
    int int1 = 5, int2 = 10;
    cout << "The minimum of " << int1 << " and " << int2 << " is " << minimum(int1, int2) << endl;
    cout << "The maximum of " << int1 << " and " << int2 << " is " << maximum(int1, int2) << endl;

    // Test with floating-point numbers
    float float1 = 5.5, float2 = 10.5;
    cout << "The minimum of " << float1 << " and " << float2 << " is " << minimum(float1, float2) << endl;
    cout << "The maximum of " << float1 << " and " << float2 << " is " << maximum(float1, float2) << endl;

    // Test with double
    double double1 = -123.456, double2 = 789.123;
    cout << "The minimum of " << double1 << " and " << double2 << " is " << minimum(double1, double2) << endl;
    cout << "The maximum of " << double1 << " and " << double2 << " is " << maximum(double1, double2) << endl;

    return 0;
}

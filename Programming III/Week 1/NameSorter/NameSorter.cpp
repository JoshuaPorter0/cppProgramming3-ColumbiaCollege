// Filename: NameSorter.cpp
// Author: Joshua Porter
// Description: Takes a file and counts the # of numbers, the sum, and average of all the numbers.
// Date: 01-01-2024

/*Pseudocode:
Open file, testing for errors
Create a data structure for holding names
Iterate through each name and add it to the data structure (dynamic array, vector, or set)
close the file

Sort names alphabetically
Print the name in the first position and last position
*/

#include <iostream>     //for printing lines
#include <fstream>      //for file input and output
#include <vector>       //for dynamic data structure
#include <algorithm>    //for alphabetic sorting
#include <string>       //for getline()

using namespace std;

int main() {
    ifstream file("LineUp.txt");
    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }

    vector<string> names; //using a vector data structure for its dynamic size, ease of use, and efficiency
    string name; //temporary variable allows compiler to save name to dynamic vector

    // Reading names from the file
    while (getline(file, name)) {
        names.push_back(name);
    }
    file.close();

    // Sorting the names alphabetically, sort comes from C++ standard library
    sort(names.begin(), names.end());

    // Displaying the results
    if (!names.empty()) {
        cout << "Front of the line: " << names.front() << endl;
        cout << "End of the line: " << names.back() << endl;
    }
    else {
        cout << "No names found in the file." << endl;
    }

    return 0;
}
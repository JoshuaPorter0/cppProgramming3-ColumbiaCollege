// Filename: DataAdditionWith2Files.cpp
// Author: Joshua Porter
// Description: Prompts user for 2 files and then adds the elements in each and saves it to a 3rd file.
// Date: 02-01-2024

/*
Start
Prompt user for three file names: input1, input2, output
Open input1 for reading
Open input2 for reading
Open output for writing

While not at the end of input1 and input2
    Read a number from input1
    Read a number from input2
    Add the two numbers
    Write the sum to the output file in the format: a+b=sum

Close input1
Close input2
Close output
Display completion message
END
*/



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputFileName1, inputFileName2, outputFileName;
    ifstream inputFile1, inputFile2;
    ofstream outputFile;

    // Prompt user for file names
    cout << "Enter the first input file name: ";
    cin >> inputFileName1;
    cout << "Enter the second input file name: ";
    cin >> inputFileName2;
    cout << "Enter the output file name: ";
    cin >> outputFileName;

    // Open files
    inputFile1.open(inputFileName1);
    inputFile2.open(inputFileName2);
    outputFile.open(outputFileName);

    if (!inputFile1.is_open() || !inputFile2.is_open()) {
        cerr << "Error opening input files." << endl;
        return 1; // Exit with error code
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; // Exit with error code
    }

    int num1, num2;
    while (inputFile1 >> num1 && inputFile2 >> num2) {
        // Read from both files and write the sum to the output file while a value exists in both files
        outputFile << num1 << "+" << num2 << "=" << (num1 + num2) << endl;
    }

    // Close files
    inputFile1.close();
    inputFile2.close();
    outputFile.close();

    cout << "Processing complete. Data has been written to " << outputFileName << endl;

    return 0;
}

// Filename: LastTenWordsOfFile.cpp
// Author: Joshua Porter
// Description: Takes a file and prints the last 10 lines of that file
// Date: 01-18-2024
/* ASSIGNMENT: 
1) Write a program that asks the user for the name of a file. 
The program should display the last ten lines of the file on the screen ("The tail of the file").  
If the file has fewer than ten lines, the entre file should be displayed, with a message the entire 
file has been displayed.  (30pts).

Note: Put at least 30 records in your file. Provide screenshot of the content of your file too. 
*/

/* Psuedocode:
Prompt the user for the name of a file.
    Check if the file exists. If not, prompt the user to re-enter the filename.

    Open the file for reading.

    Determine the number of lines in the file.

    If the file has fewer than 10 lines: (use the size of the data structure to determine this)
        Display all lines.
        Print a message indicating that the entire file has been displayed.
    If the file has 10 or more lines:
        Display only the last 10 lines.



*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::string filename;
    std::ifstream file;

    // while the user wants to print a file:
    while (true) {

        // Prompt user until a valid file is entered
        std::cout << "This program will print the last ten lines of that file.\nIf the file's path is in this directory, list just the name of the file, if it is somewhere else, list the entire Path.\n\n";
        std::cout << "Enter the name of the file (or type 'exit' to quit): ";
        std::getline(std::cin, filename);
        std::cout << "\n";


        // Check for exit condition
        if (filename == "exit") {
            break;
        }


        file.open(filename);
        if (!file) {
            std::cout << "File not found. Please enter a valid file name.\n";
            continue;
        }

        std::vector<std::string> lines;

        // Read the file into the vector data structure
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();

        // Display the last ten lines or the entire file
        // Size_t is the best variable to use here because it is non-negative, holds large indices, and is compatible with the vector data type
        size_t line_count = lines.size();
        size_t start_line = line_count < 10 ? 0 : line_count - 10; // This ternary operator is used to check if line count is < 10, if it is, set start to 0, if not set it to the line count - 10.

        for (size_t i = start_line; i < line_count; ++i) {
            std::cout << lines[i] << "\n";
        }

        if (line_count < 10) {
            std::cout << "\nThe entire file has been displayed.\n";
        }

        std::cout << "\n\t\t--------***********--------\n\n"; // Add a newline for formatting

    }

    return 0;
}
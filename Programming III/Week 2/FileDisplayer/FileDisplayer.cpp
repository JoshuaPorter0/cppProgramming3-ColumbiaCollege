// Filename: FileDisplayer.cpp
// Author: Joshua Porter
// Description: Takes a file and displays the contents in increments of 24 lines, waiting for user input to continue next 24 lines
// Date: 01-18-2024

/* Pseudocode
    Prompt user for the filename
    If there are no issues opening the file
        Open File
    Print the current line number and display the content of that line
    When the line number count is 24, pause and wait for a user input
    If there are no more entries, display "End of file"
    Close file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For system("pause")

int main() {
    std::string filename;
    std::ifstream file;

    while (true) {
        std::cout << "Enter the name of the file (or type 'exit' to quit): ";
        std::getline(std::cin, filename);

        // Check for exit condition
        if (filename == "exit") {
            break;
        }

        file.open(filename);
        if (!file) {
            std::cout << "File not found. Please enter a valid file name.\n";
            continue;
        }

        // Read and display the file content with line numbers
        std::string line;
        std::size_t line_number = 1;

        while (std::getline(file, line)) {
            std::cout << line_number << ": " << line << "\n";
            if (line_number % 3 == 0)
                std::cout << "\n";
            if (line_number % 24 == 0) {
                system("pause"); // Pause for user input
            }
            line_number++;
        }
        
        std::cout << "End of file.";

        file.close();
        std::cout << "\n\n\t\t--------********--------\n\n"; // Add a newline for formatting
    }

    return 0;
}
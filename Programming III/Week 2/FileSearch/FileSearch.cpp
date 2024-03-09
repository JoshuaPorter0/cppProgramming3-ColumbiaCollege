// Filename: FileSearcher.cpp
// Author: Joshua Porter
// Description: User inputs a file and a string to search for each line that it matches. At the end it displays the number of times it was found.
// Date: 01-18-2024

/* Pseudocode:
   Prompt User for file
   Loop until a valid file name is entered
   Open File
   Prompt User for string to search in the file (ex. "dream" "NA16-35T" or "how to")

   while(getline)
    if the line contains the searchString (cast the chars to upper/lower so capitalization wont matter)
        print line
        Results++
    Print "Number of hits: "
    Print "End of File."
    Close file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // For std::transform

// Function to convert a string to uppercase, pulled from stack overflow
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

int main() {
    while (true) {

        std::string filename, searchString, line;
        std::ifstream file;
        int results = 0;

        // Prompt User for file name
        std::cout << "Enter the name of the file or type 'exit': ";
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

        // Prompt User for string to search
        std::cout << "Enter the string to search for: ";
        std::getline(std::cin, searchString);

        // Convert search string to all lowercase
        searchString = toLower(searchString);

        // Read the file line by line and search for the string
        while (std::getline(file, line)) {
            std::string lowerLine = toLower(line); // Convert the line to lowercase and save as a separate variable
            // Check if line contains the search string
            if (lowerLine.find(searchString) != std::string::npos) {
                std::cout << line << std::endl; // Print the line
                results++; // Increment occurrences
            }
        }

        // Print the total number of hits
        std::cout << "Number of hits: " << results << std::endl;

        // Adding a space to organize queries
        
        std::cout << "\n\t\t--------********--------\n\n";

        // Close the file
        file.close();

    }
    return 0;
}


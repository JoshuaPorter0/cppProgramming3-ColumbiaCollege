// Filename: UserDescriptionFileSaver.cpp
// Author: Joshua Porter
// Description: This program asks the user for information and creates a file in HTML format
// by default it will place it in the working directory.
// Date: 01-01-2024

/* Project pseudocode:
prompt the user for their name and store it as a string
prompt user to describe themselves and store description as a variable

Create HTML content
      Stucture the HTML file with header, body, and other tags for aesthetic

Write to a HTML file by opening in write mode

Close File
Print message saying HTML file successfully created in working directory
*/

#include <iostream>
#include <fstream>
#include <string>

// Avoiding "using namespace std;" makes it easier to integrate different libraries without conflicts, though this is a small project.
using namespace std; 

int main() {
    string name, description;

    // Getting user input
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Describe yourself: ";
    getline(cin, description);

    // HTML content
    string html_content = "<html>\n\n<head>\n\n</head>\n\n<body>\n\n\t<center>\n\n\t\t<h1> " + name + " </h1>\n\n\t</center>\n\n\t<hr  />\n\n\t" + description + "\n\n\t<hr   />\n\n</body>\n\n</html>";

    // Writing to an HTML file
    ofstream file("userDescription.html");
    if (file.is_open()) {
        file << html_content;
        file.close();
        cout << "HTML file 'user_profile.html' has been created.\n";
    } else {
        cout << "Unable to create the HTML file.\n";
    }

    return 0;
}
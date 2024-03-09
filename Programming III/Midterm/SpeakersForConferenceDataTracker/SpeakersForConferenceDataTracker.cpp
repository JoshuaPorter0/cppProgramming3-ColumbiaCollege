// Filename: SpeakersForConferenceDataTracker.cpp
// Author: Joshua Porter
// Description: Stores data in an array of structures for bureau and asks user for data, then displays it.
// Date: 02-01-2024\

/* Pseudocode
Create a strucutre named Speaker with fields for name, telephoneNumber, speakingTopic, and feeRequired
Declare array of Speakers with a capacity for 10 entries
Do-while menu showing a menu for:
    1. Enter new speaker data
    2. Change existing speaker data
    3. Display speakers
    4. Exit the program
1. 
Prompt user for each field of the speaker strucutre in a for loop, validate input for feeRequired.

2.

*/

// The file "SpeakersDataExample" (this project) gives a prompt that enters random data and displays the text, used for debugging.

#include <iostream>
#include <string>
using namespace std;

struct Speaker {
    string name;
    string telephoneNumber;
    string speakingTopic;
    double feeRequired;
};

// Function Prototypes
void enterSpeakerData(Speaker& speaker);
void changeSpeakerData(Speaker& speaker);
void displayAllSpeakers(const Speaker speakers[], int currentSize);

int main() {
    const int MAX_SPEAKERS = 20;
    Speaker speakers[MAX_SPEAKERS];
    int numSpeakers = 0;
    int choice;

    do {
        cout << "Menu\n";
        cout << "1. Enter new speaker data\n";
        cout << "2. Change existing speaker data\n";
        cout << "3. Display all speakers\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Check if the input is not an integer, negating problem where user could enter incorrect values.
        if (cin.fail()) {
            cin.clear(); // Clears the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the rest of the current line, up to '\n' or the end of the buffer
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue; // Skip the rest of the loop body and present the menu again
        }

        switch (choice) {
        case 1: // Enter new speaker
            if (numSpeakers < MAX_SPEAKERS) {
                enterSpeakerData(speakers[numSpeakers++]);
            }
            else {
                cout << "Maximum number of speakers reached.\n";
            }
            break;
        case 2: // Change speaker data
            int index;
            cout << "Enter speaker index to change (0-" << numSpeakers - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < numSpeakers) {
                changeSpeakerData(speakers[index]);
            }
            else {
                cout << "Invalid index.\n";
            }
            break;
        case 3: // Display all speakers
            displayAllSpeakers(speakers, numSpeakers);
            break;
        case 4: // Exit
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void enterSpeakerData(Speaker& speaker) {
    cout << "Enter name: ";
    cin >> ws; //clears newline input
    getline(cin, speaker.name);
    cout << "Enter telephone number: ";
    getline(cin, speaker.telephoneNumber);
    cout << "Enter speaking topic: ";
    getline(cin, speaker.speakingTopic);
    do {
        cout << "Enter fee required (non-negative): ";
        cin >> speaker.feeRequired;
        if (speaker.feeRequired < 0) {
            cout << "Fee cannot be negative. Please enter a non-negative value.\n";
        }
    } while (speaker.feeRequired < 0);
}

void changeSpeakerData(Speaker& speaker) {
    cout << "Enter new data for the speaker\n";
    enterSpeakerData(speaker); // Reuse the function for entering new data
}

void displayAllSpeakers(const Speaker speakers[], int currentSize) {
    for (int i = 0; i < currentSize; ++i) {
        cout << "Speaker " << i << ": " << speakers[i].name
            << ", Telephone: " << speakers[i].telephoneNumber
            << ", Topic: " << speakers[i].speakingTopic
            << ", Fee: $" << speakers[i].feeRequired << endl;
    }
}

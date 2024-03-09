// Filename: SoccerPlayerDataTracker.cpp
// Author: Joshua Porter
// Description: Stores data in an array of structures for soccer players, data entered by the user.
// Date: 01-29-2024

/*
Write a program that stores the following data about a soccer player in a structure:
- Player’s name.
- Player’s Number.
- Points Scored by Player.

The program should keep an array of 12 of these structures. Each element is for a different player on a team.
When the program runs, it should ask the user to enter the data for each player.  
It should then show a table that lists each player’s number, name, and points scored. 
The program should also calculate and display the total points earned by the team.  
The number and name of the player who has earned the most points should also be displayed.

Input Validation: Do not accept negative values for players’ numbers or points scored. 
*/

/*  Abstract Pseudocode
Create a data structure that holds default data for a player. Include name (string), number (int), points scored (int)
Create an array named team with size 12
for each player in array 
    Prompt user "Please enter data for Player " [index of array]
        "Player Name: " << store at [index]
        "Player Number: " << store at [index]
        "Player points: " << store at [index]
            Validate input to ensure they are not negative and reprompt if it is invalid.
Display header for output table
Iterate through the array to display the name, number and points

Calculate totalPointsScored by iterating through the array and summing each players points scored
Highest Points scored function takes in a player score and compares it to the user with the highest score in a for loop, if it the score at current index is higher, index player will become top scorer.


*/


#include <iostream>
#include <String>
using namespace std;

struct Player { 
    string name;
    int number;
    int pointsScored;
};

// Function prototypes
void inputPlayerData(Player& player); //& will pass by reference to consume less memory and allows the function to modify the Player object 
void displayPlayerData(const Player team[], int size);  //const means that the data inside Player team[] can not be changed.
void calculateAndDisplayTotals(const Player team[], int size);

int main() {
    const int TEAM_SIZE = 12;
    Player team[TEAM_SIZE];

    // Input data for each player, for troubleshooting I created a file called PlayersExample.txt to easily copy/paste into cmd prompt. Located in project folder.
    for (int i = 0; i < TEAM_SIZE; ++i) {
        cout << "Enter data for player " << (i + 1) << ":\n";
        inputPlayerData(team[i]);
    }

    // Display table header
    cout << "\nNumber\tName\tPoints Scored\n";
    cout << "--------------------------------\n";

    // Display each player's data 
    displayPlayerData(team, TEAM_SIZE);

    // Calculate and display total points and top scorer
    calculateAndDisplayTotals(team, TEAM_SIZE);

    return 0;
}

void inputPlayerData(Player& player) {
    cout << "Name: ";
    cin >> ws; // Clear leading whitespace
    getline(cin, player.name);
    
    // Ensures that the input is both an interger and is non-negative.
    while (true) {
        cout << "Number (non-negative): ";
        if (cin >> player.number && player.number >= 0) {
            break; // Valid input; exit the loop.
        } else {
            cout << "Invalid input. Please enter a non-negative number.\n";
            cin.clear(); // Clears the error flags.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the input buffer.
        }
    }

    while (true) {
        cout << "Points Scored (non-negative): ";
        if (cin >> player.pointsScored && player.pointsScored >= 0) {
            break; // Valid input; exit the loop.
        }
        else {
            cout << "Invalid input. Please enter a non-negative number.\n";
            cin.clear(); // Clears the error flags.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the input buffer.
        }
    }
}

void displayPlayerData(const Player team[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << team[i].number << "\t" << team[i].name << "\t" << team[i].pointsScored << endl;
    }
}

void calculateAndDisplayTotals(const Player team[], int size) {
    int totalPoints = 0;
    Player topScorer = team[0];

    for (int i = 0; i < size; ++i) {
        totalPoints += team[i].pointsScored;
        if (team[i].pointsScored > topScorer.pointsScored) {
            topScorer = team[i];
        }
    }

    cout << "\nTotal points earned by the team: " << totalPoints << endl;
    cout << "Top scorer: " << topScorer.name << " (Number: " << topScorer.number << ", Points: " << topScorer.pointsScored << ")\n";
}

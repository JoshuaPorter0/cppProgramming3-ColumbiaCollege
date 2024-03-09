// Filename: NumberCounter.cpp
// Author: Joshua Porter
// Description: Takes a file and counts the # of numbers, the sum, and average of all the numbers.
// Date: 01-01-2024

/*Pseudocode:
Open a file titled Random.txt from working directory. Alternatively, we could program it to prompt the user for a filepath
    if file doesnt open, tell user there was an error
Create variables for numberCount, sum, and number
Use a While loop that reads every line in the file and increments the count and adds it to the sum
Close file
Output the numbers and sum to the user
Calculate the average (as a double) and output it to user
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //No need to clarify filepath since it is in my projects working directory which is by default $(ProjectDir)
    ifstream file("Random.txt");
    if (!file.is_open()) {
        cout << "Error opening file Random.txt"  << endl;
        return 1;
    }

    int count = 0;
    int sum = 0;
    int number;

    while (file >> number) {
        sum += number;
        count++;
    }

    file.close();

    cout << "Total numbers: " << count << endl;
    cout << "Sum of all numbers: " << sum << endl;

    if (count != 0) { //prevents divide by zero error
        double average = static_cast<double>(sum) / count; //cast to double so we dont get an int return data type
        cout << "Average of the numbers: " << average << endl;
    }
    else {
        cout << "No numbers to calculate average." << endl;
    }

    return 0;
}
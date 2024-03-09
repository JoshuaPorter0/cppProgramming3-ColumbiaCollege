// Filename: TestClass.cpp
// Author: Joshua Porter
// Description: Creates a class for 3 tests and tests it with a program that takes 3 user inputs for test score and displays the average.
// Date: 02-29-2024

/* Pseudocode:
Class TestScores
    Private:
        score1 as Float
        score2 as Float
        score3 as Float
    Public:
        Constructor(score1, score2, score3)
        Accessor Functions for each score
        Mutator Functions for each score
        Function CalculateAverage() returns Float

Main Program
    Create an instance of TestScores
    Prompt user for three scores
    Call mutators to set scores in TestScores object
    Calculate average using TestScores method
    Display the average
End Program
*/


#include <iostream>

using namespace std;

class TestScores {
private:
    float score1; // Again, floats will help save space for this simple program
    float score2;
    float score3;

public:
    // Constructor
    TestScores(float s1 = 0, float s2 = 0, float s3 = 0) : score1(s1), score2(s2), score3(s3) {}

    // Accessor functions
    float getScore1() const { return score1; }
    float getScore2() const { return score2; }
    float getScore3() const { return score3; }

    // Mutator functions
    void setScore1(float s) { score1 = s; }
    void setScore2(float s) { score2 = s; }
    void setScore3(float s) { score3 = s; }

    // Calculate average
    float calculateAverage() const {
        return (score1 + score2 + score3) / 3;
    }
};

int main() {
    TestScores scores; // Create TestScores object
    float s1, s2, s3;

    // Get scores from user
    cout << "Enter score 1: ";
    cin >> s1;
    scores.setScore1(s1);

    cout << "Enter score 2: ";
    cin >> s2;
    scores.setScore2(s2);

    cout << "Enter score 3: ";
    cin >> s3;
    scores.setScore3(s3);

    // Display the average of the scores
    cout << "Average score: " << scores.calculateAverage() << endl;

    return 0;
}

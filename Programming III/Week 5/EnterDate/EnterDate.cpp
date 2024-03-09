// Filename: EnterDate.cpp
// Author: Joshua Porter
// Description: Enter a date and display it in 3 different formats using a Date class with input validation for day and month.
// Date: 02-09-2024

#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int month, day, year;
    string monthNames[12] = { "January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December" };

    bool validateDay(int d) { 
        return d >= 1 && d <= 31; 
    }
    bool validateMonth(int m) { 
        return m >= 1 && m <= 12; 
    }

public:
    Date(int m, int d, int y) {
        month = validateMonth(m) ? m : 1; // Default to January if invalid
        day = validateDay(d) ? d : 1; // Defaults to 1 if the day is invalid
        // '? :' is a ternary conditional operator for using an in-else
        //  = condition ? valueifTrue : valueifFalse
        year = y; 
    }

    void setMonth(int m) {
        if (validateMonth(m)) month = m;
    }

    void setDay(int d) {
        if (validateDay(d)) day = d;
    }

    void setYear(int y) {
        year = y; 
    }

    void printFormat1() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void printFormat2() {
        cout << monthNames[month - 1] << " " << day << ", " << year << endl;
    }

    void printFormat3() {
        cout << day << " " << monthNames[month - 1] << " " << year << endl;
    }
};

int main() {
    Date date(04, 6, 1994); // December 25, 2018

    date.printFormat1(); // 12/25/2018
    date.printFormat2(); // December 25, 2018
    date.printFormat3(); // 25 December 2018
    return 0;
}

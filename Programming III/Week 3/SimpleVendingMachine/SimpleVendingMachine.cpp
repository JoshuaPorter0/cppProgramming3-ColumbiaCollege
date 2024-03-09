// Filename: SimpleVendingMachine.cpp
// Author: Joshua Porter
// Description: Displays sodas, their prices, and their quantity available. Asks the user to pick a soda and exit then submit a price.
// Date: 01-26-2024

/* Pseudocode
    Initialize drink options with names, costs, and quantities
    Initialize total earnings to zero

    While user does not want to quit
        Display drink options with prices and quantities
        Prompt user for a drink selection or to quit

        If user selects a drink
            Prompt for payment
            If payment is valid and drink is available
                Dispense drink
                Update remaining quantity of the drink
                Update total earnings
                Give change if necessary
            Else
                Display error message
        End If
    End While

    Display total earnings

End Program
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Drink {
    string name;
    double cost;
    int quantity;
};

// Function declarations
void displayMenu(Drink drinks[], int size);
int processPurchase(Drink& drink, double& totalEarnings);

int main() {
    const int SIZE = 5;
    double totalEarnings = 0.0;
    Drink drinks[SIZE] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    int choice = 0;
    while (true) {
        displayMenu(drinks, SIZE);
        cout << SIZE + 1 << ". Quit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == SIZE + 1) {
            break; // Quit
        }
        else if (choice > 0 && choice <= SIZE) {
            // Here I am playing with the fact that the compiler will convert 0 to a false and 1 to a true when analysing interger returns as a boolean
            if (!processPurchase(drinks[choice - 1], totalEarnings)) {
                cout << "Transaction cancelled.\n";
            }
        }
        else {
            cout << "Invalid selection. Please try again.\n";
        }
    }

    cout << "Total earnings: $" << fixed << setprecision(2) << totalEarnings << endl;
    return 0;
}

// Function Definitions
void displayMenu(Drink drinks[], int size) {
    cout << left << setw(5) << "No." << setw(15) << "Drink Name" << setw(8) << "Cost" << setw(20) << "Number Available" << endl;
    cout << setfill('-') << setw(48) << "-" << setfill(' ') << endl; // Makes the menu neatly formatted

    for (int i = 0; i < size; i++) {
        cout << left << setw(5) << (i + 1) // Number for each drink
            << setw(15) << drinks[i].name
            << "$" << right << setw(7) << fixed << setprecision(2) << drinks[i].cost
            << right << setw(18) << drinks[i].quantity << endl;
    }
}

// Verifies user's input, if it is valid, the program changes the value of available drinks and total earnings
int processPurchase(Drink& drink, double& totalEarnings) {
    if (drink.quantity <= 0) {
        cout << drink.name << " is sold out.\n";
        return 0;
    }

    double amount;
    cout << "Enter your payment: ";
    cin >> amount;

    if (amount < drink.cost || amount > 1.00) {
        cout << "Invalid amount. Soda costs $" << drink.cost << "\n";
        return 0;
    }

    drink.quantity--;
    totalEarnings += drink.cost;
    cout << "Here's your " << drink.name << " and $" << fixed << setprecision(2) << (amount - drink.cost) << " change.\n";
    return 1;
}

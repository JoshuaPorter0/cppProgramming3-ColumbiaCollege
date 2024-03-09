// Filename: BankAccountCreator.cpp
// Author: Joshua Porter
// Description: Stores data about a customer that is entered by the 
// Date: 01-26-2024

/* Pseudocode:
	Create an empty data structure that can hold many variable types called userData that holds empty values for 
    Name, Address, City, State, Zip code, Phone Number, Account balance, and date of last payment
	Output text and use a do-while loop to create a user menu for 
	1. Create User
	2. Edit User
	3. Display user

    Create a function for each condition


*/

#include <iostream>
#include <string>

using namespace std;

// Defining the data structure for customer account info
struct CustomerAccount {
	string name;
	string address;
	string city;
	string state;
	string zip;
	string telephoneNumber;
	double accountBalance = 0; //Default value
	string dateOfLastPayment;
};

// Creating an constant interger hold a maximum number of customers and then declaring data structure to hold MAX_CUSTOMERS number of arrays
const int MAX_CUSTOMERS = 10;
CustomerAccount customers[MAX_CUSTOMERS];


// Functions
void enterData(CustomerAccount & account);
void changeData(CustomerAccount & account);
void displayData(const CustomerAccount & account);

int main() {

    int choice;

    //Displaying the menu
    do {
        cout << "Menu: \n";
        cout << "1. Enter Data\n";
        cout << "2. Change Data\n";
        cout << "3. Display All Data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < MAX_CUSTOMERS; i++) {
                cout << "Enter data for customer " << i + 1 << ":\n";
                enterData(customers[i]);

                //Asks the user if they want to make another customer before proceeding
                    char userInput;
                    cout << "Do you want to enter data for another customer? (Y/N): ";
                    cin >> userInput;

                    if (!(userInput == 'Y' || userInput == 'y'))
                        break;
            }
            break;

        case 2:
            int customerNumber;
            cout << "Enter customer number to change data: ";
            cin >> customerNumber;
            if (customerNumber > 0 && customerNumber <= MAX_CUSTOMERS) {
                changeData(customers[customerNumber - 1]);
            }
            else {
                cout << "Invalid customer number.\n";
            }
            break;

        case 3:
            for (int i = 0; i < MAX_CUSTOMERS; i++) {
                cout << "Customer " << (i + 1) << endl;
                displayData(customers[i]);
            }
            break;

        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Enter a number that is between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;

}

//declared functions

    void enterData(CustomerAccount & account) {
        cout << "Name: ";
        cin.ignore();
        getline(cin, account.name);
        cout << "Address: ";
        getline(cin, account.address);
        cout << "City: ";
        getline(cin, account.city);
        cout << "State: ";
        getline(cin, account.state);
        cout << "Zip: ";
        getline(cin, account.zip);
        cout << "Telephone Number: ";
        getline(cin, account.telephoneNumber);
        cout << "Account Balance: ";
        cin >> account.accountBalance;
        while (account.accountBalance < 0) {
            cout << "Account balance cannot be negative. Please enter again: ";
            cin >> account.accountBalance;
        }
        cin.ignore(); // This line ignores the newline character left by the last cin
        cout << "Date of Last Payment (MMDDYYYY): ";
        getline(cin, account.dateOfLastPayment);
    }

    void changeData(CustomerAccount& account) {
        int choice;
        //sub-menu for changing the customer data
        do {
            cout << "Current Data for: " << account.name << "\n";
            displayData(account); 

            cout << "Select the data you wish to change:\n";
            cout << "1. Name\n";
            cout << "2. Address\n";
            cout << "3. City\n";
            cout << "4. State\n";
            cout << "5. Zip\n";
            cout << "6. Telephone Number\n";
            cout << "7. Account Balance\n";
            cout << "8. Date of Last Payment\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); 

            switch (choice) {
            case 1:
                cout << "Enter new Name: ";
                getline(cin, account.name);
                break;
            case 2:
                cout << "Enter new Address: ";
                getline(cin, account.address);
                break;
            case 3:
                cout << "Enter new City: ";
                getline(cin, account.city);
                break;
            case 4:
                cout << "Enter new State: ";
                getline(cin, account.state);
                break;
            case 5:
                cout << "Enter new Zip: ";
                getline(cin, account.zip);
                break;
            case 6:
                cout << "Enter new Telephone Number: ";
                getline(cin, account.telephoneNumber);
                break;
            case 7:
                cout << "Enter new Account Balance: ";
                cin >> account.accountBalance;
                while (account.accountBalance < 0) {
                    cout << "Account balance cannot be negative. Please enter again: ";
                    cin >> account.accountBalance;
                }
                cin.ignore();
                break;
            case 8:
                cout << "Enter new Date of Last Payment: ";
                getline(cin, account.dateOfLastPayment);
                break;
            case 9:
                cout << "Exiting to main menu.\n";
                break;
            default:
                cout << "Invalid choice, please select a valid number.\n";
            }
        } while (choice != 9);
    }

    //Displays each customer's data
    void displayData(const CustomerAccount& account) {
        if (!account.name.empty()) { //Ensures that it is only displayed if it is not an empty value.
            cout << "Name: " << account.name << "\n";
        }
        if (!account.address.empty()) {
            cout << "Address: " << account.address << "\n";
        }
        if (!account.city.empty()) {
            cout << "City: " << account.city << "\n";
        }
        if (!account.state.empty()) {
            cout << "State: " << account.state << "\n";
        }
        if (!account.zip.empty()) {
            cout << "Zip: " << account.zip << "\n";
        }
        if (!account.telephoneNumber.empty()) {
            cout << "Telephone Number: " << account.telephoneNumber << "\n";
        }
        //This Line assumes that the default value of accountBalance is == 0.
        if (!(account.accountBalance == 0)) {
            cout << "Account Balance: $" << account.accountBalance << "\n";
        }
        if (!account.dateOfLastPayment.empty()) {
            cout << "Date of Last Payment: " << account.dateOfLastPayment << "\n\n";
        }
    }




// Filename: MonthlyBudgeter.cpp
// Author: Joshua Porter
// Description: Takes a pre-defined budget and prompts the user for their monthly spending and tells them how much they are over/under each expense and total
// Date: 01-18-2024

/* Pseudocode
	Create a data structure which holds the default data for the monthly budget.
	Createa a function to prompt the user how much money they spent for a given expense this month
	Create a function to display the report and how much above or udner budget they were for each category and the total budget. 
	Implement the int main with the defined structure and the functions
*/

#include <iostream> // For standard I/O operations
#include <iomanip>  // For formatted output
using namespace std;

struct MonthlyBudget { //change these values to change your monthly budget. In the future, we can make this entered by the user inside the program
    double housing = 500.00;
    double utilities = 150.00;
    double householdExpenses = 65.00;
    double transportation = 50.00;
    double food = 250.00;
    double medical = 30.00;
    double insurance = 100.00;
    double entertainment = 150.00;
    double clothing = 75.00;
    double miscellaneous = 50.00;
};

//function for the user to enter monthly expenses
void enterMonthlyExpenses(MonthlyBudget& budget) {
    cout << "Enter the amounts spent for each expense this month:\n";
    cout << "Housing: $"; cin >> budget.housing;
    cout << "Utilities: $"; cin >> budget.utilities;
    cout << "Household Expenses: $"; cin >> budget.householdExpenses;
    cout << "Transportation: $"; cin >> budget.transportation;
    cout << "Food: $"; cin >> budget.food;
    cout << "Medical: $"; cin >> budget.medical;
    cout << "Insurance: $"; cin >> budget.insurance;
    cout << "Entertainment: $"; cin >> budget.entertainment;
    cout << "Clothing: $"; cin >> budget.clothing;
    cout << "Miscellaneous: $"; cin >> budget.miscellaneous;
    cout << "\n\n";
}

//function to display the report in a neat and formatted way
void displayBudgetReport(const MonthlyBudget& spent, const MonthlyBudget& budget) {
    //This calculates the difference between two parameters
    auto calculateDifference = [](double budget, double spent) { return budget - spent; };
    
    //calculating the total budget and total spent. We could use a for loop if it was not a structure data type but it is more advanced and harder to understand
    double totalBudget = budget.housing + budget.utilities + budget.householdExpenses +
        budget.transportation + budget.food + budget.medical +
        budget.insurance + budget.entertainment + budget.clothing +
        budget.miscellaneous;

    double totalSpent = spent.housing + spent.utilities + spent.householdExpenses +
        spent.transportation + spent.food + spent.medical +
        spent.insurance + spent.entertainment + spent.clothing +
        spent.miscellaneous;


    cout << "Budget Report:\n";
    cout << "Category\t\tBudget\t\tSpent\t\tOver(Under)\n";
    cout << "--------\t\t------\t\t----\t\t----------\n";

    // Housing
    cout << "Housing\t\t\t$" << budget.housing << "\t\t$" << spent.housing
        << "\t\t$" << calculateDifference(budget.housing, spent.housing) << "\n";

    cout << "Utilities\t\t$" << budget.utilities << "\t\t$" << spent.utilities
        << "\t\t$" << calculateDifference(budget.utilities, spent.utilities) << "\n";
    
    cout << "Household Expenses\t$" << budget.householdExpenses << "\t\t$" << spent.householdExpenses
        << "\t\t$" << calculateDifference(budget.householdExpenses, spent.householdExpenses) << "\n";

    cout << "Transportation\t\t$" << budget.transportation << "\t\t$" << spent.transportation
        << "\t\t$" << calculateDifference(budget.transportation, spent.transportation) << "\n";

    cout << "Food\t\t\t$" << budget.food << "\t\t$" << spent.food
        << "\t\t$" << calculateDifference(budget.food, spent.food) << "\n";

    cout << "Medical\t\t\t$" << budget.medical << "\t\t$" << spent.medical
        << "\t\t$" << calculateDifference(budget.medical, spent.medical) << "\n";

    cout << "Insurance\t\t$" << budget.insurance << "\t\t$" << spent.insurance
        << "\t\t$" << calculateDifference(budget.insurance, spent.insurance) << "\n";

    cout << "Entertainment\t\t$" << budget.entertainment << "\t\t$" << spent.entertainment
        << "\t\t$" << calculateDifference(budget.entertainment, spent.entertainment) << "\n";

    cout << "Clothing\t\t$" << budget.clothing << "\t\t$" << spent.clothing
        << "\t\t$" << calculateDifference(budget.clothing, spent.clothing) << "\n";

    cout << "Miscellaneous\t\t$" << budget.miscellaneous << "\t\t$" << spent.miscellaneous
        << "\t\t$" << calculateDifference(budget.miscellaneous, spent.miscellaneous) << "\n";




    cout << "\nTotal Budget: $" << totalBudget << "\n";
    cout << "Total Spent: $" << totalSpent << "\n";

    cout << "Total Over/Under: $" << (totalBudget - totalSpent) << "\n";
}


int main() {
    MonthlyBudget budget; // Initialized with default budget values as defined in the struct
    MonthlyBudget spent = {}; // Initialize all spent categories to zero

    // Ensures cout prints floating point numbers in a fixed decimal format
    cout << fixed << setprecision(2);

    enterMonthlyExpenses(spent); // Prompt user to enter monthly expenses
    displayBudgetReport(spent, budget); // Display the budget report

    return 0;
}



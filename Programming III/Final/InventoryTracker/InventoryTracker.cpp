// Filename: InventoryTracker.cpp
// Author: Joshua Porter
// Description: Functions as a inventory where all parts are the same, parts can be added, removed, or viewed
// Date: 02-29-2024

/* Pseudocode
Structure Bin
        Description as String
        Count as Integer
    End Structure

    Declare bins[10] as Bin

    Initialize bins with part descriptions and initial counts:

    Function AddParts(reference bin as Bin, quantity as Integer)
        If bin.Count + quantity <= 30 Then
            bin.Count += quantity
        Else
            Print "Cannot add more parts. Bin capacity exceeded."
        End If
    End Function

    Function RemoveParts(reference bin as Bin, quantity as Integer)
        If bin.Count - quantity >= 0 Then
            bin.Count -= quantity
        Else
            Print "Cannot remove more parts than the bin contains."
        End If
    End Function

    Function DisplayBins(bins as Array of Bin)
        For each bin in bins
            Print bin.Description and bin.Count
        Next bin
    End Function

    Function SelectBin() as Integer
        Print "Select a bin by number (0-9) or -1 to quit: "
        Input selection
        Return selection
    End Function

    Function UpdateBin(bins as Array of Bin, index as Integer)
        Print "Selected bin: ", bins[index].Description
        Print "Add or Remove parts? (A/R): "
        Input action
        Print "Enter quantity: "
        Input quantity

        If quantity < 0 Then
            Print "Invalid quantity. Positive numbers only."
            Return
        End If

        If action is "A" Then
            Call AddParts(bins[index], quantity)
        ElseIf action is "R" Then
            Call RemoveParts(bins[index], quantity)
        Else
            Print "Invalid action. Please select 'A' to add or 'R' to remove parts."
        End If
    End Function

    Main
        Do
            Call DisplayBins(bins)
            index = Call SelectBin()
            If index = -1 Then
                Exit Program
            ElseIf index >= 0 AND index < 10 Then
                Call UpdateBin(bins, index)
            Else
                Print "Invalid selection. Please try again."
            End If
        Loop
    End Main

End Program
*/
#include <iostream>
#include <string>

using namespace std;

// Define the Bin structure
struct Bin {
    string description;
    int count;
};

// Function prototypes
void AddParts(Bin& bin, int quantity);
void RemoveParts(Bin& bin, int quantity);
void DisplayBins(const Bin bins[], int size);
int SelectBin();
void UpdateBin(Bin bins[], int index);

int main() {
    // Initialize bins
    Bin bins[10] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    bool running = true;
    while (running) {
        DisplayBins(bins, 10); // Display all bins
        cout << "Select a bin to update (0-9) or -1 to quit: ";
        int index = SelectBin();
        if (!(index >= 0 && index < 10)) {
            running = false;
        }
        else if (index >= 0 && index < 10) {
            UpdateBin(bins, index); // Update selected bin
        }
        else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }

    return 0;
}

// Display all bins
void DisplayBins(const Bin bins[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ": " << bins[i].description << " - " << bins[i].count << " parts" << endl;
    }
}

// Select a bin to update
int SelectBin() {
    int selection;
    cin >> selection;
    return selection;
}

// Update the selected bin
void UpdateBin(Bin bins[], int index) {
    cout << "Selected: " << bins[index].description << endl;
    cout << "Add or Remove parts? (A/R): ";
    char action;
    cin >> action;
    cout << "Enter quantity: ";
    int quantity;
    cin >> quantity;

    if (quantity < 0) {
        cout << "Invalid quantity. Positive numbers only." << endl;
        return;
    }

    if (action == 'A' || action == 'a') {
        AddParts(bins[index], quantity);
    }
    else if (action == 'R' || action == 'r') {
        RemoveParts(bins[index], quantity);
    }
    else {
        cout << "Invalid action. Please select 'A' to add or 'R' to remove parts." << endl;
    }
}

// Increase the part count in a bin
void AddParts(Bin& bin, int quantity) {
    if (bin.count + quantity > 30) {
        cout << "Cannot add more parts. Bin capacity exceeded." << endl;
    }
    else {
        bin.count += quantity;
        cout << "Parts added successfully." << endl;
    }
}

// Decrease the part count in a bin
void RemoveParts(Bin& bin, int quantity) {
    if (bin.count - quantity < 0) {
        cout << "Cannot remove more parts than the bin contains." << endl;
    }
    else {
        bin.count -= quantity;
        cout << "Parts removed successfully." << endl;
    }
}

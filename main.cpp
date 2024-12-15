#include <iostream>
#include <string>
#include <limits>
#include "GroceryTracker.h"  // Includes the GroceryTracker class definition to manage grocery-related operations.

using namespace std;

/**
 * @brief The main entry point of the Grocery Tracker program.
 *
 * Initializes the GroceryTracker, creates a backup, and provides a menu for user interaction.
 * Users can search for item frequencies, print all frequencies, view a histogram, or exit.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
    const string inputFile = "CS210_Project_Three_Input_File.txt";
    const string backupFile = "frequency.dat";

    // Instantiate GroceryTracker with the input file.
    const GroceryTracker tracker(inputFile);

    // Create a backup of the frequency data.
    tracker.WriteBackupFile(backupFile);

    int choice = 0;

    while (choice != 4) {
        // Display the menu options.
        cout << "\nMENU\n"
             << "1. Search for an item frequency\n"
             << "2. Print all item frequencies\n"
             << "3. Print histogram of item frequencies\n"
             << "4. Exit\n"
             << "Enter your choice: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Validate input.
        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
            case 1: {  // Search for an item's frequency.
                cout << "Enter item name to search frequency: ";
                string item;
                getline(cin, item);
                int freq = tracker.GetItemFrequency(item);
                cout << item << ": " << freq << endl;
                break;
            }
            case 2: {  // Print all item frequencies.
                cout << "\nFREQUENCY LIST\n";
                tracker.PrintAllFrequencies();
                break;
            }
            case 3: {  // Print a histogram of item frequencies.
                cout << "\nHISTOGRAM\n";
                tracker.PrintHistogram();
                break;
            }
            case 4:  // Exit the program.
                cout << "Exiting program.\n";
                break;
            default:  // Should not occur due to validation.
                cout << "Invalid option.\n";
                break;
        }
    }

    return 0;
}

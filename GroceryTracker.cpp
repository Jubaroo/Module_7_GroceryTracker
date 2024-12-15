/**
 * @file GroceryTracker.cpp
 * @brief Implementation of the GroceryTracker class methods.
 *
 * This file contains the definitions of the GroceryTracker class's member functions,
 * which manage grocery item frequencies, handle file operations, and provide various
 * functionalities such as searching, printing frequencies, and generating histograms.
 */

#include "GroceryTracker.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief Constructs a GroceryTracker object and initializes item frequencies from a file.
 *
 * This constructor calls the LoadItemsFromFile method to read grocery items from the
 * specified input file and populate the internal frequency map.
 *
 * @param inputFile The path to the input file containing grocery items.
 */
GroceryTracker::GroceryTracker(const string& inputFile) {
    LoadItemsFromFile(inputFile);
}

/**
 * @brief Loads grocery items from the input file and populates the frequency map.
 *
 * This helper function reads each line from the input file, processes the item names,
 * and updates the frequency count in the `itemFrequency` map accordingly.
 * If the file cannot be opened, an error message is displayed.
 *
 * @param inputFile The path to the input file containing grocery items.
 */
void GroceryTracker::LoadItemsFromFile(const string& inputFile) {
    ifstream inFS(inputFile);
    if (!inFS.is_open()) {
        cerr << "Error: Could not open " << inputFile << endl;
        return;
    }

    string item;
    while (getline(inFS, item)) {
        if (!item.empty()) {
            itemFrequency[item]++;
        }
    }
    inFS.close();
}

/**
 * @brief Retrieves the frequency of a specific grocery item.
 *
 * This function searches for the specified item in the frequency map and returns
 * its count. If the item is not found, it returns 0.
 *
 * @param item The name of the grocery item to query.
 * @return int The frequency count of the specified item.
 */
int GroceryTracker::GetItemFrequency(const string& item) const {
    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        return it->second;
    }
    return 0;
}

/**
 * @brief Prints all grocery items along with their frequencies.
 *
 * This function iterates through the frequency map and displays each item
 * along with its corresponding count.
 */
void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

/**
 * @brief Generates and prints a histogram of grocery item frequencies.
 *
 * This function creates a visual representation (histogram) of item frequencies
 * by printing each item followed by a series of asterisks (*) corresponding to its count.
 */
void GroceryTracker::PrintHistogram() const {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

/**
 * @brief Writes the current frequency data to a backup file.
 *
 * This function serializes the frequency map and saves it to the specified backup file,
 * ensuring that the data can be restored or analyzed later.
 * If the file cannot be written to, an error message is displayed.
 *
 * @param backupFile The path to the backup file where frequency data will be saved.
 */
void GroceryTracker::WriteBackupFile(const string& backupFile) const {
    ofstream outFS(backupFile);
    if (!outFS.is_open()) {
        cerr << "Error: Could not write to " << backupFile << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFS << pair.first << " " << pair.second << endl;
    }
    outFS.close();
}

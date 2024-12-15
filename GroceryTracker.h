#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

/**
 * @class GroceryTracker
 * @brief Manages and tracks the frequency of grocery items.
 *
 * The GroceryTracker class provides functionalities to load grocery items from
 * an input file, retrieve the frequency of specific items, print all item frequencies,
 * generate a histogram of item frequencies, and create a backup of frequency data.
 */
class GroceryTracker {
public:
    /**
     * @brief Constructs a GroceryTracker object and initializes item frequencies from a file.
     *
     * This constructor reads grocery items from the specified input file and populates
     * the internal frequency map with the count of each item.
     *
     * @param inputFile The path to the input file containing grocery items.
     */
    GroceryTracker(const string& inputFile);

    /**
     * @brief Retrieves the frequency of a specific grocery item.
     *
     * This function searches for the specified item in the frequency map and returns
     * its count. If the item is not found, it returns 0.
     *
     * @param item The name of the grocery item to query.
     * @return int The frequency count of the specified item.
     */
    int GetItemFrequency(const string& item) const;

    /**
     * @brief Prints all grocery items along with their frequencies.
     *
     * This function iterates through the frequency map and displays each item
     * along with its corresponding count.
     */
    void PrintAllFrequencies() const;

    /**
     * @brief Generates and prints a histogram of grocery item frequencies.
     *
     * This function creates a visual representation (histogram) of item frequencies
     * by printing each item followed by a series of asterisks (*) corresponding to its count.
     */
    void PrintHistogram() const;

    /**
     * @brief Writes the current frequency data to a backup file.
     *
     * This function serializes the frequency map and saves it to the specified backup file,
     * ensuring that the data can be restored or analyzed later.
     *
     * @param backupFile The path to the backup file where frequency data will be saved.
     */
    void WriteBackupFile(const string& backupFile) const;

private:
    map<string, int> itemFrequency; /**<
                                       * @brief Maps grocery item names to their frequency counts.
                                       *
                                       * The key is the item name (string), and the value is the number
                                       * of times the item appears in the input data.
                                       */

    /**
     * @brief Loads grocery items from the input file and populates the frequency map.
     *
     * This helper function reads each line from the input file, processes the item names,
     * and updates the frequency count in the `itemFrequency` map accordingly.
     *
     * @param inputFile The path to the input file containing grocery items.
     */
    void LoadItemsFromFile(const string& inputFile);
};

#endif // GROCERYTRACKER_H

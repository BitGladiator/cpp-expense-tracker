#include "../include/FileHandler.h"
#include <fstream>
#include <iostream>

// Saves a list of expenses to a file in CSV format
void FileHandler::saveToFile(const std::string& filename, const std::vector<Expense>& expenses) {
    std::ofstream file(filename); // Open file for writing
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << "\n";
        return; // Exit if file can't be opened
    }

    // Write each expense as a CSV line
    for (const auto& expense : expenses) {
        file << expense.toCSV() << "\n";
    }

    file.close(); // Close the file
    std::cout << "Expenses saved to file.\n";
}

// Loads a list of expenses from a file
std::vector<Expense> FileHandler::loadFromFile(const std::string& filename) {
    std::vector<Expense> expenses;
    std::ifstream file(filename); // Open file for reading
    std::string line;

    if (!file.is_open()) {
        std::cerr << "No file found, starting fresh.\n";
        return expenses; // Return empty list if file doesn't exist
    }

    // Read each line and convert it into an Expense object
    while (std::getline(file, line)) {
        if (!line.empty()) {
            expenses.push_back(Expense::fromCSV(line));
        }
    }

    file.close(); // Close the file
    std::cout << "Loaded " << expenses.size() << " expenses from file.\n";
    return expenses;
}

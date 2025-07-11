#include "../include/FileHandler.h"
#include <fstream>
#include <iostream>

void FileHandler::saveToFile(const std::string& filename, const std::vector<Expense>& expenses) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << "\n";
        return;
    }

    for (const auto& expense : expenses) {
        file << expense.toCSV() << "\n";
    }

    file.close();
    std::cout << "Expenses saved to file.\n";
}

std::vector<Expense> FileHandler::loadFromFile(const std::string& filename) {
    std::vector<Expense> expenses;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "No file found, starting fresh.\n";
        return expenses; // return empty if file doesn't exist
    }

    while (std::getline(file, line)) {
        if (!line.empty()) {
            expenses.push_back(Expense::fromCSV(line));
        }
    }

    file.close();
    std::cout << "Loaded " << expenses.size() << " expenses from file.\n";
    return expenses;
}

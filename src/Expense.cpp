#include "../include/Expense.h"
#include <iostream>
#include <sstream>

// Default constructor
Expense::Expense() : amount(0.0), category(""), date(""), note("") {}

// Parameterized constructor
Expense::Expense(double amt, const std::string &cat, const std::string &dt, const std::string &nt)
    : amount(amt), category(cat), date(dt), note(nt) {}

// Getters
double Expense::getAmount() const { return amount; }
std::string Expense::getCategory() const { return category; }
std::string Expense::getDate() const { return date; }
std::string Expense::getNote() const { return note; }

// Display expense details in a readable format
void Expense::display() const
{
    std::cout << "Date: " << date
              << " | Amount: $" << amount
              << " | Category: " << category
              << " | Note: " << note << std::endl;
}

// Convert expense to CSV format (for saving to file)
std::string Expense::toCSV() const
{
    std::stringstream ss;
    ss << date << "," << amount << "," << category << "," << note;
    return ss.str();
}

// Create an Expense object from a CSV line (for loading from file)
Expense Expense::fromCSV(const std::string &line)
{
    std::stringstream ss(line);
    std::string date, amountStr, category, note;

    // Parse the CSV line into components
    std::getline(ss, date, ',');
    std::getline(ss, amountStr, ',');
    std::getline(ss, category, ',');
    std::getline(ss, note);

    // Check for missing mandatory fields
    if (date.empty() || amountStr.empty() || category.empty()) {
        throw std::invalid_argument("Malformed CSV line: " + line);
    }

    double amt = 0.0;

    // Convert amount string to double, with error handling
    try {
        amt = std::stod(amountStr);
    } catch (const std::exception &e) {
        throw std::invalid_argument("Invalid amount: " + amountStr + " in line: " + line);
    }

    return Expense(amt, category, date, note);
}

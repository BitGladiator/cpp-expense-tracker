#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

// The Expense class represents a single financial expense with details.
class Expense
{
private:
    double amount;        // The amount of the expense
    std::string category; // The category of the expense (e.g., Food, Travel)
    std::string date;     // The date of the expense (e.g., "2025-07-09")
    std::string note;     // Optional note/description for the expense

public:
    // Default constructor
    Expense();

    // Parameterized constructor to initialize an expense
    Expense(double amt, const std::string &cat, const std::string &dt, const std::string &nt);

    // Getters for each member variable
    double getAmount() const;
    std::string getCategory() const;
    std::string getDate() const;
    std::string getNote() const;

    // Display the expense details to the console
    void display() const;

    // Convert expense to a CSV-formatted string (for saving to file)
    std::string toCSV() const;

    // Static method to create an Expense object from a CSV line (for loading from file)
    static Expense fromCSV(const std::string &line);
};

#endif // EXPENSE_H

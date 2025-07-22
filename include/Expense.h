#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

// Represents a single financial expense
class Expense
{
private:
    double amount;        // Expense amount
    std::string category; // Expense category (e.g., Food, Travel)
    std::string date;     // Date of expense (e.g., "2025-07-09")
    std::string note;     // Optional note or description

public:
    // Default constructor
    Expense();

    // Constructor with all fields
    Expense(double amt, const std::string &cat, const std::string &dt, const std::string &nt);

    // Get amount
    double getAmount() const;

    // Get category
    std::string getCategory() const;

    // Get date
    std::string getDate() const;

    // Get note
    std::string getNote() const;

    // Print expense details
    void display() const;

    // Convert to CSV string
    std::string toCSV() const;

    // Create from CSV string
    static Expense fromCSV(const std::string &line);
};

#endif // EXPENSE_H

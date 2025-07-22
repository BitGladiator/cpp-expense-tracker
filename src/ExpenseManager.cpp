#include "../include/ExpenseManager.h"
#include <iostream>
#include <fstream>
#include <filesystem> // For handling files and directories

// Display all expenses
void ExpenseManager::showAllExpenses() const {
    if (expenses.empty()) {
        std::cout << "No expenses to display.\n";
        return;
    }

    std::cout << "\n--- All Expenses ---\n";
    for (const auto &e : expenses) {
        e.display();
    }
}

// Get reference to all expenses
std::vector<Expense>& ExpenseManager::getExpenses() {
    return expenses;
}

// Calculate total amount spent
double ExpenseManager::getTotalSpent() const {
    double total = 0.0;
    for (const auto &expense : expenses) {
        total += expense.getAmount();
    }
    return total;
}

// Show expenses by category
void ExpenseManager::showExpensesByCategory(const std::string &category) const {
    bool found = false;

    for (const auto &expense : expenses) {
        if (expense.getCategory() == category) {
            expense.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No expenses found in category: " << category << "\n";
    }
}

// Show monthly summary for a given month (YYYY-MM)
void ExpenseManager::showMonthlySummary(const std::string &monthYear) const {
    double total = 0.0;
    bool found = false;

    for (const auto &expense : expenses) {
        if (expense.getDate().substr(0, 7) == monthYear) {
            expense.display();
            total += expense.getAmount();
            found = true;
        }
    }

    if (found) {
        std::cout << "Total Spent in " << monthYear << ": $" << total << "\n";
    } else {
        std::cout << "No expenses found for " << monthYear << "\n";
    }
}

// Export monthly report to a text file
void ExpenseManager::exportMonthlyReport(const std::string &monthYear) const {
    std::string filename = "reports/report-" + monthYear + ".txt";
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Failed to create report file.\n";
        return;
    }

    double total = 0.0;
    bool found = false;

    outFile << "Monthly Expense Report for " << monthYear << "\n\n";

    for (const auto &expense : expenses) {
        if (expense.getDate().substr(0, 7) == monthYear) {
            outFile << "Date: " << expense.getDate()
                    << " | Amount: $" << expense.getAmount()
                    << " | Category: " << expense.getCategory()
                    << " | Note: " << expense.getNote() << "\n";
            total += expense.getAmount();
            found = true;
        }
    }

    if (found) {
        outFile << "\nTotal Spent: $" << total << "\n";
        std::cout << "Report exported to " << filename << "\n";
    } else {
        std::cout << "No expenses found for " << monthYear << ". Empty report created.\n";
        outFile << "No expenses found.\n";
    }

    outFile.close();
}

// Replace current expenses with a new list
void ExpenseManager::setExpenses(const std::vector<Expense> &newExpenses) {
    expenses = newExpenses;
}

// Set monthly budget limit
void ExpenseManager::setMonthlyBudgetThreshold(double threshold) {
    monthlyBudgetThreshold = threshold;
}

// Get current budget threshold
double ExpenseManager::getMonthlyBudgetThreshold() const {
    return monthlyBudgetThreshold;
}

// Warn user if spending exceeds budget
void ExpenseManager::checkBudgetWarning(const std::string &monthYear) const {
    if (monthlyBudgetThreshold <= 0.0)
        return;

    double total = 0.0;
    for (const auto &expense : expenses) {
        if (expense.getDate().substr(0, 7) == monthYear) {
            total += expense.getAmount();
        }
    }

    if (total > monthlyBudgetThreshold) {
        std::cout << "WARNING: Total spending in " << monthYear
                  << " is $" << total << ", which exceeds your budget of $"
                  << monthlyBudgetThreshold << "!\n";
    }
}

// Check if there are unsaved changes
bool ExpenseManager::isModified() const {
    return hasUnsavedChanges;
}

// Mark all changes as saved
void ExpenseManager::markSaved() {
    hasUnsavedChanges = false;
}

// Mark that changes have been made
void ExpenseManager::markModified() {
    hasUnsavedChanges = true;
}

// Add a new expense
void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
    hasUnsavedChanges = true;
}

// Edit an existing expense
void ExpenseManager::editExpense(size_t index, const Expense& updated) {
    if (index < expenses.size()) {
        expenses[index] = updated;
        markModified();  
    }
}

// Delete an expense by index
void ExpenseManager::deleteExpense(size_t index) {
    if (index < expenses.size()) {
        expenses.erase(expenses.begin() + index);
        markModified();  
    }
}

// Search expenses by keyword in category, note, or date
void ExpenseManager::searchExpenses(const std::string &query) const {
    bool found = false;

    std::cout << "\n--- Search Results for \"" << query << "\" ---\n";

    for (const auto &expense : expenses) {
        if (expense.getCategory().find(query) != std::string::npos ||
            expense.getNote().find(query) != std::string::npos ||
            expense.getDate().find(query) != std::string::npos)
        {
            expense.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching expenses found.\n";
    }
}

#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include "Expense.h"
#include <vector>

class ExpenseManager
{
private:
    std::vector<Expense> expenses;               // List of all expenses
    double monthlyBudgetThreshold = 0.0;         // Monthly budget limit
    bool hasUnsavedChanges = false;              // Flag to track unsaved changes

public:
    // Add a new expense
    void addExpense(const Expense &e);

    // Display all expenses
    void showAllExpenses() const;

    // Get total amount spent
    double getTotalSpent() const;

    // Check if data was modified
    bool isModified() const;

    // Mark changes as saved
    void markSaved();

    // Mark data as modified
    void markModified();

    // Set monthly budget limit
    void setMonthlyBudgetThreshold(double threshold);

    // Get monthly budget limit
    double getMonthlyBudgetThreshold() const;

    // Warn if spending exceeds monthly budget
    void checkBudgetWarning(const std::string& monthYear) const;

    // Replace all expenses with a new list
    void setExpenses(const std::vector<Expense>& newExpenses);

    // Show expenses by a specific category
    void showExpensesByCategory(const std::string& category) const;

    // Export report for a specific month
    void exportMonthlyReport(const std::string& monthYear) const;

    // Display a summary for a specific month
    void showMonthlySummary(const std::string& monthYear) const;

    // Edit an existing expense
    void editExpense(size_t index, const Expense& updated);

    // Delete an expense by index
    void deleteExpense(size_t index);

    // Search expenses by keyword
    void searchExpenses(const std::string &query) const;

    // Access all expenses (e.g. for saving)
    std::vector<Expense> &getExpenses();
};

#endif // EXPENSE_MANAGER_H

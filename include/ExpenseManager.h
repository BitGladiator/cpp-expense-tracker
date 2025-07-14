#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include "Expense.h"
#include <vector>

class ExpenseManager
{
private:
    std::vector<Expense> expenses; // Stores all user expenses

public:
    // Add a new expense to the list
    void addExpense(const Expense &e);

    // Display all saved expenses
    void showAllExpenses() const;
    double getTotalSpent() const;
    void setExpenses(const std::vector<Expense>& newExpenses);
    void showExpensesByCategory(const std::string& category) const;
    void exportMonthlyReport(const std::string& monthYear) const;
    void showMonthlySummary(const std::string& monthYear) const;
    // Provide access to all expenses (useful for saving)
    std::vector<Expense> &getExpenses();
};

#endif // EXPENSE_MANAGER_H

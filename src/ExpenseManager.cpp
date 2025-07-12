#include "../include/ExpenseManager.h"
#include <iostream>

void ExpenseManager::addExpense(const Expense &e)
{
    expenses.push_back(e);
    std::cout << "Expense added successfully.\n";
}

void ExpenseManager::showAllExpenses() const
{
    if (expenses.empty())
    {
        std::cout << "No expenses to display.\n";
        return;
    }

    std::cout << "\n--- All Expenses ---\n";
    for (const auto &e : expenses)
    {
        e.display();
    }
}

std::vector<Expense> &ExpenseManager::getExpenses()
{
    return expenses;
}
double ExpenseManager::getTotalSpent() const
{
    double total = 0.0;
    for (const auto &expense : expenses)
    {
        total += expense.getAmount();
    }
    return total;
}
void ExpenseManager::showExpensesByCategory(const std::string &category) const
{
    bool found = false;

    for (const auto &expense : expenses)
    {
        if (expense.getCategory() == category)
        {
            expense.display();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No expenses found in category: " << category << "\n";
    }
}
void ExpenseManager::showMonthlySummary(const std::string& monthYear) const {
    double total = 0.0;
    bool found = false;

    for (const auto& expense : expenses) {
        // Assuming date format is "YYYY-MM-DD"
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

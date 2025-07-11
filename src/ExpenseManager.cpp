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
double ExpenseManager::getTotalSpent() const {
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.getAmount();
    }
    return total;
}

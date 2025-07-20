#include "../include/ExpenseManager.h"
#include <iostream>
#include <fstream>
#include <filesystem> // C++17


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
void ExpenseManager::showMonthlySummary(const std::string &monthYear) const
{
    double total = 0.0;
    bool found = false;

    for (const auto &expense : expenses)
    {
        // Assuming date format is "YYYY-MM-DD"
        if (expense.getDate().substr(0, 7) == monthYear)
        {
            expense.display();
            total += expense.getAmount();
            found = true;
        }
    }

    if (found)
    {
        std::cout << "Total Spent in " << monthYear << ": $" << total << "\n";
    }
    else
    {
        std::cout << "No expenses found for " << monthYear << "\n";
    }
}
void ExpenseManager::exportMonthlyReport(const std::string &monthYear) const
{
    std::string filename = "reports/report-" + monthYear + ".txt";

    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Failed to create report file.\n";
        return;
    }

    double total = 0.0;
    bool found = false;

    outFile << "Monthly Expense Report for " << monthYear << "\n\n";

    for (const auto &expense : expenses)
    {
        if (expense.getDate().substr(0, 7) == monthYear)
        {
            outFile << "Date: " << expense.getDate()
                    << " | Amount: $" << expense.getAmount()
                    << " | Category: " << expense.getCategory()
                    << " | Note: " << expense.getNote() << "\n";

            total += expense.getAmount();
            found = true;
        }
    }

    if (found)
    {
        outFile << "\nTotal Spent: $" << total << "\n";
        std::cout << "Report exported to " << filename << "\n";
    }
    else
    {
        std::cout << "No expenses found for " << monthYear << ". Empty report created.\n";
        outFile << "No expenses found.\n";
    }

    outFile.close();
}
void ExpenseManager::setExpenses(const std::vector<Expense> &newExpenses)
{
    expenses = newExpenses;
}
void ExpenseManager::setMonthlyBudgetThreshold(double threshold)
{
    monthlyBudgetThreshold = threshold;
}

double ExpenseManager::getMonthlyBudgetThreshold() const
{
    return monthlyBudgetThreshold;
}

void ExpenseManager::checkBudgetWarning(const std::string &monthYear) const
{
    if (monthlyBudgetThreshold <= 0.0)
        return;

    double total = 0.0;
    for (const auto &expense : expenses)
    {
        if (expense.getDate().substr(0, 7) == monthYear)
        {
            total += expense.getAmount();
        }
    }

    if (total > monthlyBudgetThreshold)
    {
        std::cout << "WARNING: Total spending in " << monthYear
                  << " is $" << total << ", which exceeds your budget of $"
                  << monthlyBudgetThreshold << "!\n";
    }
}
bool ExpenseManager::isModified() const {
    return hasUnsavedChanges;
}

void ExpenseManager::markSaved() {
    hasUnsavedChanges = false;
}
void ExpenseManager::markModified() {
    hasUnsavedChanges = true;
}

// Modify addExpense() like this:
void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
    hasUnsavedChanges = true;
}
void ExpenseManager::editExpense(size_t index, const Expense& updated) {
    if (index < expenses.size()) {
        expenses[index] = updated;
        markModified();  
    }
}

void ExpenseManager::deleteExpense(size_t index) {
    if (index < expenses.size()) {
        expenses.erase(expenses.begin() + index);
        markModified();  
    }
}
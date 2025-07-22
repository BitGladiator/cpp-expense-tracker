#ifndef MENU_H
#define MENU_H

#include "ExpenseManager.h"
#include <string>

class Menu {
private:
    ExpenseManager& manager; // Reference to the expense manager

    // Get expense details from user input
    Expense getExpenseFromUser() const;

    // Display reports and summary options
    void showReportsMenu();

    // Handle editing an expense
    void editExpense();

    // Handle deleting an expense
    void deleteExpense();

public:
    // Constructor that takes a reference to ExpenseManager
    Menu(ExpenseManager& mgr);

    // Show the main menu
    void show();
};

#endif // MENU_H

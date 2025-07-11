#include "../include/Menu.h"
#include "../include/FileHandler.h"
#include <iostream>
#include <limits>

Menu::Menu(ExpenseManager &mgr) : manager(mgr) {}

void Menu::show()
{
    int choice;

    do
    {
        std::cout << "\n===== Expense Tracker Menu =====\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. Show All Expenses\n";
        std::cout << "3. Save and Exit\n";
        std::cout << "4. Show Total Amount Spent\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Fix input stream if user enters wrong type
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
        }

        switch (choice)
        {
        case 1:
        {
            Expense e = getExpenseFromUser();
            manager.addExpense(e);
            break;
        }
        case 2:
            manager.showAllExpenses();
            break;
        case 3:
            FileHandler::saveToFile("data/expenses.csv", manager.getExpenses());
            std::cout << "Saved and exiting. Goodbye!\n";
            break;
        case 4:
            std::cout << "Total spent: $" << manager.getTotalSpent() << "\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);
}

Expense Menu::getExpenseFromUser() const
{
    double amount;
    std::string category, date, note;

    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cin.ignore(); // flush newline

    std::cout << "Enter category: ";
    std::getline(std::cin, category);

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);

    std::cout << "Enter note: ";
    std::getline(std::cin, note);

    return Expense(amount, category, date, note);
}

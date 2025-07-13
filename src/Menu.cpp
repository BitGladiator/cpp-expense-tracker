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
        std::cout << "3. Reports and Analytics\n";
        std::cout << "4. Save and Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

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
            showReportsMenu();  // ✅ this is your submenu
            break;
        case 4:
            FileHandler::saveToFile("data/expenses.csv", manager.getExpenses());
            std::cout << "Saved and exiting. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);
}

void Menu::showReportsMenu()
{
    int reportChoice;

    do
    {
        std::cout << "\n=== Reports and Analytics ===\n";
        std::cout << "1. Show Total Spent\n";
        std::cout << "2. Filter by Category\n";
        std::cout << "3. Show Monthly Summary\n";
        std::cout << "4. Export Monthly Report\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> reportChoice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            reportChoice = -1;
        }

        switch (reportChoice)
        {
        case 1:
            std::cout << "Total spent: $" << manager.getTotalSpent() << "\n";
            break;
        case 2:
        {
            std::string category;
            std::cin.ignore();
            std::cout << "Enter category: ";
            std::getline(std::cin, category);
            manager.showExpensesByCategory(category);
            break;
        }
        case 3:
        {
            std::string monthYear;
            std::cin.ignore();
            std::cout << "Enter month and year (YYYY-MM): ";
            std::getline(std::cin, monthYear);
            manager.showMonthlySummary(monthYear);
            break;
        }
        case 4:
        {
            std::string monthYear;
            std::cin.ignore();
            std::cout << "Enter month and year (YYYY-MM): ";
            std::getline(std::cin, monthYear);
            manager.exportMonthlyReport(monthYear);
            break;
        }
        case 5:
            std::cout << "Returning to main menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (reportChoice != 5);
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

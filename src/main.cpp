#include "../include/ExpenseManager.h"
#include "../include/FileHandler.h"
#include "../include/Menu.h"
#include "../include/PasswordManager.h"
#include <iostream>

int main() {
    // 🔐 Password check before anything else
    if (!PasswordManager::verifyPassword("data/password.txt")) {
        std::cout << "Access denied. Exiting.\n";
        return 1;
    }

    ExpenseManager manager;

    // ✅ Load existing expenses
    manager.setExpenses(FileHandler::loadFromFile("data/expenses.csv"));

    // 📋 Start main menu
    Menu menu(manager);
    menu.show();

    return 0;
}

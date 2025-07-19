#include "../include/ExpenseManager.h"
#include "../include/FileHandler.h"
#include "../include/Menu.h"
#include "../include/PasswordManager.h"
#include <iostream>
#include <fstream> // for checking if file exists

int main() {
    std::string passwordFile = "password.txt";

    //  If password file doesn't exist, set it once
    std::ifstream infile(passwordFile);
    if (!infile.good()) {
        std::cout << "No password set. Let's set one up.\n";
        PasswordManager::setPassword(passwordFile);
    } else {
        if (!PasswordManager::verifyPassword(passwordFile)) {
            std::cout << "Access denied. Exiting.\n";
            return 1;
        }
    }

    ExpenseManager manager;

    // Load existing expenses
    manager.setExpenses(FileHandler::loadFromFile("data/expenses.csv"));

    // Start main menu
    Menu menu(manager);
    menu.show();

    return 0;
}

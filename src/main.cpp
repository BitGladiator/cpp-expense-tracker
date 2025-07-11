#include "../include/ExpenseManager.h"
#include "../include/FileHandler.h"
#include "../include/Menu.h"

int main() {
    ExpenseManager manager;

    // Load from file at startup
    manager.getExpenses() = FileHandler::loadFromFile("data/expenses.csv");

    // Run the menu
    Menu menu(manager);
    menu.show();

    return 0;
}

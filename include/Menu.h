#ifndef MENU_H
#define MENU_H

#include "ExpenseManager.h"
#include <string>

class Menu {
private:
    ExpenseManager& manager;

    Expense getExpenseFromUser() const;

public:
    Menu(ExpenseManager& mgr);
    void show();
};

#endif // MENU_H

#include "../include/Expense.h"
#include<iostream>
int main() {
    Expense e(200.5, "Groceries", "2025-07-09", "Weekly shopping");
    e.display();

    std::string csv = e.toCSV();
    std::cout << "CSV: " << csv << std::endl;

    Expense f = Expense::fromCSV(csv);
    f.display();

    return 0;
}

#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense
{
private:
    double amount;
    std::string category;
    std::string date;
    std::string note;

public:
    Expense();
    Expense(double amt, const std::string &cat, const std::string &dt, const std::string &nt);

    double getAmount() const;
    std::string getCategory() const;
    std::string getDate() const;
    std::string getNote() const;

    void display() const;

    std::string toCSV() const;
    static Expense fromCSV(const std::string &line);
};

#endif

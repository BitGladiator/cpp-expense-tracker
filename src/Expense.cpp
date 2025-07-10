#include "../include/Expense.h"
#include <iostream>
#include <sstream>

Expense::Expense() : amount(0.0), category(""), date(""), note("") {}

Expense::Expense(double amt, const std::string &cat, const std::string &dt, const std::string &nt)
    : amount(amt), category(cat), date(dt), note(nt) {}

double Expense::getAmount() const { return amount; }
std::string Expense::getCategory() const { return category; }
std::string Expense::getDate() const { return date; }
std::string Expense::getNote() const { return note; }

void Expense::display() const
{
    std::cout << "Date: " << date
              << " | Amount: $" << amount
              << " | Category: " << category
              << " | Note: " << note << std::endl;
}

std::string Expense::toCSV() const
{
    std::stringstream ss;
    ss << date << "," << amount << "," << category << "," << note;
    return ss.str();
}

Expense Expense::fromCSV(const std::string &line)
{
    std::stringstream ss(line);
    std::string date, amountStr, category, note;

    std::getline(ss, date, ',');
    std::getline(ss, amountStr, ',');
    std::getline(ss, category, ',');
    std::getline(ss, note, ',');

    double amt = std::stod(amountStr);
    return Expense(amt, category, date, note);
}

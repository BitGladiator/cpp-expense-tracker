#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "Expense.h"
#include <vector>
#include <string>

class FileHandler {
public:
    // Save list of expenses to a file
    static void saveToFile(const std::string& filename, const std::vector<Expense>& expenses);

    // Load expenses from a file
    static std::vector<Expense> loadFromFile(const std::string& filename);
};

#endif // FILE_HANDLER_H

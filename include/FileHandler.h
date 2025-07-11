#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "Expense.h"
#include <vector>
#include <string>

class FileHandler {
public:
    static void saveToFile(const std::string& filename, const std::vector<Expense>& expenses);
    static std::vector<Expense> loadFromFile(const std::string& filename);
};

#endif // FILE_HANDLER_H

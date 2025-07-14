#include "../include/PasswordManager.h"
#include <fstream>
#include <iostream>

bool PasswordManager::verifyPassword(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open password file.\n";
        return false;
    }

    std::string storedPassword;
    std::getline(file, storedPassword);
    file.close();

    std::string input;
    std::cout << "Enter password to continue: ";
    std::cin >> input;

    return input == storedPassword;
}

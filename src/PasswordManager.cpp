#include "../include/PasswordManager.h"
#include "../include/picosha2.h"
#include <fstream>
#include <iostream>
#include <string>

bool PasswordManager::verifyPassword(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Password file not found.\n";
        return false;
    }

    std::string storedHash;
    std::getline(file, storedHash);
    file.close();

    std::string inputPassword;
    std::cout << "Enter password: ";
    std::getline(std::cin, inputPassword);

    std::string hashedInput = picosha2::hash256_hex_string(inputPassword);

    return hashedInput == storedHash;
}

void PasswordManager::setPassword(const std::string& filePath) {
    std::string newPassword;
    std::cout << "Set a new password: ";
    std::getline(std::cin, newPassword);

    std::string hashed = picosha2::hash256_hex_string(newPassword);

    std::ofstream out(filePath);
    if (out) {
        out << hashed << "\n";
        out.close();
        std::cout << "Password set successfully.\n";
    } else {
        std::cerr << "Failed to write password file.\n";
    }
}

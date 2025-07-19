#include "../include/PasswordManager.h"
#include "../include/picosha2.h"
#include <fstream>
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

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
    inputPassword = getMaskedPassword();

    std::string hashedInput = picosha2::hash256_hex_string(inputPassword);

    return hashedInput == storedHash;
}

void PasswordManager::setPassword(const std::string& filePath) {
    std::string newPassword;
    std::cout << "Set a new password: ";
    newPassword = getMaskedPassword();

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
std::string PasswordManager::getMaskedPassword() {
    std::string password;
    struct termios oldt, newt;

    // Turn off terminal echo
    tcgetattr(STDIN_FILENO, &oldt);          // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~ECHO;                   // Disable ECHO
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply settings

    std::getline(std::cin, password);        // Read password

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    std::cout << std::endl;                  // Print newline for clean output

    return password;
}

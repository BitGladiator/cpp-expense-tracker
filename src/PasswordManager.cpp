#include "../include/PasswordManager.h"
#include "../include/picosha2.h"
#include <fstream>
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

// Verifies the user-entered password against the stored hash in the file
bool PasswordManager::verifyPassword(const std::string &filePath)
{
    std::ifstream file(filePath); // Open the password file
    if (!file)
    {
        std::cerr << "Password file not found.\n";
        return false; // File doesn't exist or couldn't be opened
    }

    std::string storedHash;
    std::getline(file, storedHash); // Read the stored hash
    file.close();

    std::string inputPassword;
    std::cout << "Enter password: ";
    inputPassword = getMaskedPassword(); // Get user input without showing it

    // Hash the entered password and compare with stored hash
    std::string hashedInput = picosha2::hash256_hex_string(inputPassword);

    return hashedInput == storedHash;
}

// Sets a new password by hashing and storing it in a file
void PasswordManager::setPassword(const std::string &filePath)
{
    std::string newPassword;
    std::cout << "Set a new password: ";
    newPassword = getMaskedPassword(); // Get new password from user

    std::string hashed = picosha2::hash256_hex_string(newPassword); // Hash the password

    std::ofstream out(filePath); // Open file to write hashed password
    if (out)
    {
        out << hashed << "\n";
        out.close();
        std::cout << "Password set successfully.\n";
    }
    else
    {
        std::cerr << "Failed to write password file.\n";
    }
}

// Reads a password from user input without displaying it on screen
std::string PasswordManager::getMaskedPassword()
{
    std::string password;
    struct termios oldt, newt;

    // Save current terminal settings and disable echo
    tcgetattr(STDIN_FILENO, &oldt); // Get current settings
    newt = oldt;
    newt.c_lflag &= ~ECHO;                   // Disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

    std::getline(std::cin, password); // Read password from user

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore original settings
    std::cout << std::endl;                  // Add a newline for formatting

    return password; // Return the entered password
}

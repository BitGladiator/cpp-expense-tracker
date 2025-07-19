#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <string>

class PasswordManager {
public:
    static bool verifyPassword(const std::string& filePath);
    static void setPassword(const std::string& filePath);
private:
    static std::string getMaskedPassword(); 
};


#endif 

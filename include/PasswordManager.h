#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <string>

class PasswordManager {
public:
    static bool verifyPassword(const std::string& filepath);
};

#endif

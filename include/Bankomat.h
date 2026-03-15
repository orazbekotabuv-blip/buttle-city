#ifndef BANKOMAT_H
#define BANKOMAT_H

#include <vector>
#include <string>
#include "User.h"

class Bankomat {
private:
    std::vector<User> users;
    User* currentUser;
    std::string filename;
    
    User* findUser(const std::string& login);
    void loadData();
    void saveData();
    
public:
    Bankomat();
    ~Bankomat();
    
    bool login(const std::string& login, const std::string& password);
    void logout();
    
    bool showBalance() const;
    bool withdraw(long long amount);
    bool transfer(const std::string& toLogin, long long amount);
    
    bool isLoggedIn() const { return currentUser != nullptr; }
    std::string getCurrentUser() const { return currentUser ? currentUser->getLogin() : ""; }
};

#endif

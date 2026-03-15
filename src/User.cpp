#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string login;
    std::string password;  // Keyinroq buni hash qilamiz
    long long balance;
    
public:
    User() : login(""), password(""), balance(0) {}
    User(std::string login, std::string password, long long balance);
    
    // Getter metodlar
    std::string getLogin() const { return login; }
    std::string getPassword() const { return password; }
    long long getBalance() const { return balance; }
    
    // Setter metodlar
    void setBalance(long long newBalance) { balance = newBalance; }
    void addMoney(long long amount) { balance += amount; }
    bool withdrawMoney(long long amount);
    
    // Validatsiya
    bool checkPassword(const std::string& pass) const { return password == pass; }
};

#endif

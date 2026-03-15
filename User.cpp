#include "../include/User.h"

User::User(std::string login, std::string password, long long balance) 
    : login(login), password(password), balance(balance) {}

bool User::withdrawMoney(long long amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

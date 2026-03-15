#include "../include/Bankomat.h"
#include "../include/FileManager.h"
#include <iostream>
#include <algorithm>

Bankomat::Bankomat() : currentUser(nullptr) {
    loadData();
}

Bankomat::~Bankomat() {
    saveData();
}

void Bankomat::loadData() {
    FileManager fm;
    users = fm.loadUsers();
}

void Bankomat::saveData() {
    FileManager fm;
    fm.saveUsers(users);
}

User* Bankomat::findUser(const std::string& login) {
    for (auto& user : users) {
        if (user.getLogin() == login) {
            return &user;
        }
    }
    return nullptr;
}

bool Bankomat::login(const std::string& login, const std::string& password) {
    User* user = findUser(login);
    if (user && user->checkPassword(password)) {
        currentUser = user;
        return true;
    }
    return false;
}

void Bankomat::logout() {
    currentUser = nullptr;
}

bool Bankomat::showBalance() const {
    if (!currentUser) return false;
    std::cout << "\n💰 Sizning balansingiz: " << currentUser->getBalance() << " so'm\n";
    return true;
}

bool Bankomat::withdraw(long long amount) {
    if (!currentUser) return false;
    
    if (currentUser->withdrawMoney(amount)) {
        std::cout << "✅ Muvaffaqiyatli! Qoldiq: " << currentUser->getBalance() << std::endl;
        saveData();
        return true;
    }
    
    std::cout << "❌ Xato: Yetarli mablag' yo'q yoki noto'g'ri miqdor!\n";
    return false;
}

bool Bankomat::transfer(const std::string& toLogin, long long amount) {
    if (!currentUser) return false;
    
    User* receiver = findUser(toLogin);
    if (!receiver) {
        std::cout << "❌ Xato: Foydalanuvchi topilmadi!\n";
        return false;
    }
    
    if (amount <= 0) {
        std::cout << "❌ Xato: Miqdor musbat bo'lishi kerak!\n";
        return false;
    }
    
    if (currentUser->withdrawMoney(amount)) {
        receiver->addMoney(amount);
        std::cout << "✅ " << amount << " so'm " << toLogin << " ga o'tkazildi!\n";
        std::cout << "💰 Sizning balans: " << currentUser->getBalance() << std::endl;
        saveData();
        return true;
    }
    
    std::cout << "❌ Xato: Yetarli mablag' yo'q!\n";
    return false;
}

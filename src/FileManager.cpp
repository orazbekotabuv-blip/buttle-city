#include "../include/FileManager.h"
#include <fstream>
#include <iostream>

FileManager::FileManager(const std::string& file) : filename(file) {}

bool FileManager::saveUsers(const std::vector<User>& users) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    
    for (const auto& user : users) {
        file << user.getLogin() << " " 
             << user.getPassword() << " " 
             << user.getBalance() << std::endl;
    }
    file.close();
    return true;
}

std::vector<User> FileManager::loadUsers() {
    std::vector<User> users;
    std::ifstream file(filename);
    
    if (file.is_open()) {
        std::string login, pass;
        long long bal;
        while (file >> login >> pass >> bal) {
            users.push_back(User(login, pass, bal));
        }
        file.close();
    } else {
        createDefaultUsers();
        users = loadUsers();  // Qayta yuklash
    }
    
    return users;
}

void FileManager::createDefaultUsers() {
    std::vector<User> defaultUsers;
    defaultUsers.push_back(User("user1", "1234", 5000000));
    defaultUsers.push_back(User("admin", "admin", 10000000));
    saveUsers(defaultUsers);
}

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <vector>
#include <string>
#include "User.h"

class FileManager {
private:
    std::string filename;
    
public:
    FileManager(const std::string& file = "data/users.txt");
    
    bool saveUsers(const std::vector<User>& users);
    std::vector<User> loadUsers();
    void createDefaultUsers();
};

#endif

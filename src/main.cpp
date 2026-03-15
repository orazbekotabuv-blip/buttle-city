#include <iostream>
#include <limits>
#include "../include/Bankomat.h"

void clearScreen() {
    // Konsolni tozalash
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printMenu() {
    std::cout << "\n╔════════════════════════╗\n";
    std::cout << "║    BANKOMAT MENUSI    ║\n";
    std::cout << "╠════════════════════════╣\n";
    std::cout << "║ 1. Balans ko'rish     ║\n";
    std::cout << "║ 2. Pul yechish        ║\n";
    std::cout << "║ 3. Pul o'tkazish      ║\n";
    std::cout << "║ 4. Chiqish             ║\n";
    std::cout << "╚════════════════════════╝\n";
    std::cout << "Tanlov: ";
}

int getValidNumber() {
    int num;
    while (!(std::cin >> num)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "❌ Noto'g'ri kiritish. Qayta urinib ko'ring: ";
    }
    return num;
}

int main() {
    Bankomat atm;
    
    std::cout << "╔══════════════════════════╗\n";
    std::cout << "║   BANKOMAT SIMULYATORI   ║\n";
    std::cout << "╚══════════════════════════╝\n\n";
    
    // Login
    std::string login, password;
    std::cout << "🔑 Tizimga kirish\n";
    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Parol: ";
    std::cin >> password;
    
    if (!atm.login(login, password)) {
        std::cout << "\n❌ Noto'g'ri login yoki parol!\n";
        return 1;
    }
    
    std::cout << "\n✅ Xush kelibsiz, " << login << "!\n";
    
    // Asosiy menu
    int choice;
    do {
        printMenu();
        choice = getValidNumber();
        
        switch (choice) {
            case 1:
                atm.showBalance();
                break;
                
            case 2: {
                long long amount;
                std::cout << "Yechmoqchi bo'lgan miqdor: ";
                std::cin >> amount;
                atm.withdraw(amount);
                break;
            }
                
            case 3: {
                std::string toUser;
                long long amount;
                std::cout << "Pul o'tkazmoqchi bo'lgan foydalanuvchi: ";
                std::cin >> toUser;
                std::cout << "Miqdor: ";
                std::cin >> amount;
                atm.transfer(toUser, amount);
                break;
            }
                
            case 4:
                std::cout << "\n👋 Xayr! Tizimdan chiqildi.\n";
                break;
                
            default:
                std::cout << "❌ Noto'g'ri tanlov! 1-4 oralig'ida tanlang.\n";
        }
        
        if (choice != 4) {
            std::cout << "\n⏎ Davom etish uchun Enter ni bosing...";
            std::cin.ignore();
            std::cin.get();
            // clearScreen(); // Agar kerak bo'lsa
        }
        
    } while (choice != 4);
    
    return 0;
}

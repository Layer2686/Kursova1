#include "CUser.h"
#include "CAdmin.h"
#include "CBuyer.h"
#include <iostream>

int main() {
    int choice;
    std::string username, password, role;

    do {
        std::cout << "\n=== MAIN MENU ==="
                  << "\n1. Login"
                  << "\n2. Register"
                  << "\n3. Exit"
                  << "\nEnter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: { // Логін
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;

                if (CUser::loginFromFile(username, password, role)) {
                    std::cout << "Login successful! Welcome, " << username << "!\n";

                    CUser* user = nullptr;
                    if (role == "admin") {
                        user = new CAdmin(username, password);
                    } else {
                        user = new CBuyer(username, password);
                    }

                    user->showMenu();
                    delete user;
                } else {
                    std::cout << "Login failed! Invalid credentials.\n";
                }
                break;
            }

            case 2: { // Реєстрація
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;

                if (CUser::registerUser(username, password)) {
                    std::cout << "Registration successful! You can now login.\n";
                } else {
                    std::cout << "Registration failed! Username may already exist.\n";
                }
                break;
            }

            case 3: // Вихід
                std::cout << "Exiting program. Goodbye!\n";
            return 0;

            default:
                std::cout << "Invalid choice! Please select 1-3.\n";
            break;
        }

    }
    while (true);

    return 0;
}
#include "CUser.h"
CUser::CUser(const std::string& name, const std::string& pass)
: username(name), password(pass) {}

bool CUser::login(const std::string& name, const std::string& pass) const {

    return username == name && password == pass;
}

std::string CUser::getUsername() const
{
    return username;
}
void CUser::switchUser() {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Login\n";
        std::cout << "2. Register\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string inputUsername, inputPassword;

        switch (choice) {
            case 1: // Login
                std::cout << "Enter username: ";
            std::cin >> inputUsername;
            std::cout << "Enter password: ";
            std::cin >> inputPassword;

            if (CUser::loginFromFile(inputUsername, inputPassword)) {
                std::cout << "Login successful!\n";
                return; // Exit after login
            } else {
                std::cout << "Login failed. Invalid credentials.\n";
            }
            break;

            case 2: // Register
                std::cout << "Enter new username: ";
            std::cin >> inputUsername;
            std::cout << "Enter new password: ";
            std::cin >> inputPassword;

            if (CUser::registerUser(inputUsername, inputPassword)) {
                std::cout << "Registration successful!\n";
                // return; // Exit after registration
            } else {
                std::cout << "Registration failed. Username may already exist.\n";
            }
            break;

            case 3: // Exit
                std::cout << "Exiting...\n";
            break;

            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    }
    while (choice != 3);
}

bool CUser::loginFromFile(const std::string& username, const std::string& password) {
    std::ifstream file("users.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening users.txt\n";
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string fileUsername, filePassword;
        if (ss >> fileUsername >> filePassword) {
            if (fileUsername == username && filePassword == password) {
                return true;
            }
        }
    }

    return false;
}

bool CUser::registerUser(const std::string& username, const std::string& password) {
    // Перевіряємо чи користувач вже існує
    if (loginFromFile(username, password)) {
        std::cout << "User already exists!\n";
        return false;
    }

    // Додаємо нового користувача
    std::ofstream file("users.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening users.txt for writing\n";
        return false;
    }

    file << username << " " << password << "\n";
    file.close();

    std::cout << "User registered successfully!\n";
    return true;
}
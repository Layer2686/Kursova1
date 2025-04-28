#include "CUser.hpp"

CUser::CUser(const std::string& name, const std::string& pass)
    : username(name), password(pass) {}

bool CUser::login(const std::string& name, const std::string& pass) const
{
    return username == name && password == pass;
}

std::string CUser::getUsername() const
{
    return username;
}

bool CUser::loginFromFile(const std::string& username, const std::string& password, std::string& outRole) {
    std::ifstream file("users.txt");
    if (!file.is_open())
    {
        std::cerr << "Error opening users.txt\n";
        return false;
    }

    std::string line;
    while (std::getline(file, line))
        {
        std::stringstream ss(line);
        std::string fileUsername, filePassword, role;
        if (ss >> fileUsername >> filePassword >> role)
            {
                if (fileUsername == username && filePassword == password)
                {
                outRole = role;
                return true;
                }
            }
        }
        return false;
        }

bool CUser::registerUser(const std::string& username,const std::string& password,const std::string& role) {
    std::string dummyRole;
    if (loginFromFile(username, password, dummyRole))
    {
        std::cout << "User already exists!\n";
        return false;
    }

    std::ofstream file("users.txt", std::ios::app);
    if (!file.is_open())
    {
        std::cerr << "Error opening users.txt for writing\n";
        return false;
    }

    file << username << " " << password << " " << role << "\n";
    file.close();
    return true;
}

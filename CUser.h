#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

class CUser {
private:
    std::string username;
    std::string password;

public:
    CUser(const std::string& name, const std::string& pass);
    virtual ~CUser() = default;

    bool login(const std::string& name, const std::string& pass) const;
    std::string getUsername() const;

    static bool loginFromFile(const std::string& username, const std::string& password, std::string& outRole);
    static bool registerUser(const std::string& username, const std::string& password, const std::string& role = "user");
    virtual void showMenu() = 0;
};
#pragma once
#include <string>

class CProduct {
private:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    CProduct(int id, const std::string& name, double price, int quantity);

    // Геттери
    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    // Сеттери
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);

    void printInfo() const; // Вивід інформації про товар
    void printInfoCart() const;
};
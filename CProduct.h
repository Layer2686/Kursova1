#pragma once
#include <string>
#include <iostream>

class CProduct {
private:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    CProduct(int id, const std::string& name, double price, int quantity);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setPrice(double newPrice);
    void setQuantity(int newQuantity); // Виправлено оголошення (1 параметр)

    void printInfo() const;
    void printInfoCart() const;
};
#include "CProduct.h"

CProduct::CProduct(int id, const std::string& name, double price, int quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

int CProduct::getId() const { return id; }
std::string CProduct::getName() const { return name; }
double CProduct::getPrice() const { return price; }
int CProduct::getQuantity() const { return quantity; }

void CProduct::setPrice(double newPrice)
{
    price = newPrice;
}

// Виправлена реалізація (1 параметр)
void CProduct::setQuantity(int newQuantity)
{
    if (newQuantity >= 0)
    {
        quantity = newQuantity;
    }
}

void CProduct::printInfo() const {
    std::cout << "ID: " << id
              << ", Name: " << name
              << ", Price: " << price
              << ", Quantity: " << quantity << std::endl;
}

void CProduct::printInfoCart() const {
    std::cout << "ID: " << id
              << ", Name: " << name
              << ", Price: " << price
              << ", Quantity: " << 1 << std::endl;
}
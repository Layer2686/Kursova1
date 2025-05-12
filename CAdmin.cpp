#include "CAdmin.h"
#include <iostream>

CAdmin::CAdmin(const std::string& username, const std::string& password)
    : CUser(username, password) {}

void CAdmin::showMenu()
{
    Catalog catalog;
    catalog.loadFromFile();

    int choice;
    do
    {
        std::cout << "\n=== ADMIN MENU ==="
                  << "\n1. Add product"
                  << "\n2. Remove product"
                  << "\n3. Edit product"
                  << "\n4. View all products"
                  << "\n0. Exit"
                  << "\nEnter choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1: addProduct(catalog); break;
            case 2: removeProduct(catalog); break;
            case 3: editProduct(catalog); break;
            case 4: viewAllProducts(catalog); break;
            case 0: std::cout << "Logging out...\n"; break;
            default: std::cout << "Invalid choice!\n";
        }
    }
    while (choice != 0);

    catalog.saveToFile();
}

void CAdmin::addProduct(Catalog& catalog)
{
    int id, quantity;
    double price;
    std::string name;

    std::cout << "Enter product ID: ";
    std::cin >> id;
    std::cout << "Enter product name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    catalog.addProduct(CProduct(id, name, price, quantity));
}

void CAdmin::removeProduct(Catalog& catalog)
{
    int productId;
    std::cout << "Enter product ID to remove: ";
    std::cin >> productId;
    catalog.removeProduct(productId);
}

void CAdmin::editProduct(Catalog& catalog) {
    int productId, newQuantity;
    double newPrice;
    std::cout << "Enter product ID to edit: ";
    std::cin >> productId;
    std::cout << "Enter new price: ";
    std::cin >> newPrice;
    std::cout << "Enter new quantity: ";
    std::cin >> newQuantity;

    CProduct* product = catalog.findProduct(productId);
    if (product) {
        product->setPrice(newPrice);
        product->setQuantity(newQuantity); // Виправлений виклик (1 аргумент)
    }
}

void CAdmin::viewAllProducts(Catalog& catalog)
{
    catalog.printAllProducts();
}
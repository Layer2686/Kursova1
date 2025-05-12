#include "CBuyer.h"
#include <iostream>
#include <limits>
CBuyer::CBuyer(const std::string& username, const std::string& password)
    : CUser(username, password) {}

void CBuyer::showMenu() {
    Catalog catalog;
    catalog.loadFromFile();

    int choice;
    do
    {
        std::cout << "\n=== BUYER MENU ==="
                  << "\n1. View products"
                  << "\n2. Add to cart"
                  << "\n3. View cart"
                  << "\n4. Checkout"
                  << "\n0. Exit"
                  << "\nEnter choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1: viewProducts(catalog); break;
            case 2: addToCart(catalog); break;
            case 3: viewCart(catalog); break;
            case 4: checkout(catalog); break;
            case 0: std::cout << "Logging out...\n"; break;
            default: std::cout << "Invalid choice!\n";
        }
    }
    while (choice != 0);
}

void CBuyer::viewProducts(Catalog& catalog)
{
    catalog.printAllProducts();
}

void CBuyer::addToCart(Catalog& catalog) {
    int productId;

    // Виведення списку товарів
    catalog.printAllProducts();

    // Вибір товару за ID
    std::cout << "Enter product ID to add: ";
    std::cin >> productId;

    // Пошук товару в каталозі
    CProduct* product = catalog.findProduct(productId);
    if (!product) {
        std::cout << "Error: Product not found.\n";
        return;
    }

    // Перевірка наявності товару
    if (product->getQuantity() == 0) {
        std::cout << "Sorry, this product is currently out of stock.\n";
        return; // Вийти з методу, якщо товару немає
    }

    // Введення кількості з перевірками
    int quantity;
    std::cout << "Available quantity: " << product->getQuantity() << "\n";
    std::cout << "Enter quantity to add: ";

    while (!(std::cin >> quantity) || quantity <= 0 || quantity > product->getQuantity()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid quantity. Please enter a number between 1 and "
                  << product->getQuantity() << ": ";
    }

    // Додавання до кошика та оновлення залишку
    cart.emplace_back(productId, quantity);
    product->setQuantity(product->getQuantity() - quantity);
    std::cout << "Added " << quantity << " items of product ID " << productId << " to cart.\n";
}

void CBuyer::viewCart(Catalog& catalog) {
    double total = 0;
    std::cout << "\n=== YOUR CART ===\n";

    for (const auto& item : cart) {
        int productId = item.first;
        int quantity = item.second;
        CProduct* product = catalog.findProduct(productId);

        if (product) {
            std::cout << "ID: " << product->getId()
                      << ", Name: " << product->getName()
                      << ", Price: " << product->getPrice()
                      << ", Quantity: " << quantity
                      << ", Subtotal: " << (product->getPrice() * quantity) << " UAH\n";
            total += product->getPrice() * quantity;
        }
    }
    std::cout << "TOTAL: " << total << " UAH\n";
}

void CBuyer::checkout(Catalog& catalog) {
    viewCart(catalog);
    if (cart.empty()) {
        std::cout << "Your cart is empty!\n";
        return;
    }

    std::cout << "Confirm purchase (1 - Yes, 0 - No): ";
    int confirm;
    std::cin >> confirm;

    if (confirm == 1) {
        for (const auto& item : cart) {
            int productId = item.first;
            int quantity = item.second;
            CProduct* product = catalog.findProduct(productId);

            if (product) {
                product->setQuantity(product->getQuantity() - quantity);
            }
        }
        cart.clear();
        catalog.saveToFile();
        std::cout << "Purchase completed! Thank you!\n";
    }
}
#include "CBuyer.h"
#include <iostream>

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

void CBuyer::addToCart(Catalog& catalog)
{
    int productId;
    std::cout << "Enter product ID to add: ";
    std::cin >> productId;

    if (catalog.findProduct(productId))
    {
        cart.push_back(productId);
        std::cout << "Product added to cart!\n";
    }
    else
    {
        std::cout << "Product not found!\n";
    }
}

void CBuyer::viewCart(Catalog& catalog)
{
    double total = 0;
    std::cout << "\n=== YOUR CART ===\n";
    for (int id : cart)
    {
        CProduct* product = catalog.findProduct(id);
        if (product)
        {
            product->printInfoCart();
            total += product->getPrice();
        }
    }
    std::cout << "Total: " << total << " UAH\n";
}

void CBuyer::checkout(Catalog& catalog)
{
    viewCart(catalog);
    std::cout << "Confirm purchase (1 - Yes, 0 - No): ";
    int confirm;
    std::cin >> confirm;

    if (confirm == 1)
    {
        for (int id : cart)
        {
            CProduct* product = catalog.findProduct(id);
            if (product)
            {
                product->setQuantity(product->getQuantity() - 1);
            }
        }
        cart.clear();
        catalog.saveToFile();
        std::cout << "Purchase completed!\n";
    }
}
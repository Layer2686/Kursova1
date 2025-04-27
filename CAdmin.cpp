#include "CAdmin.h"
// Конструктор
CAdmin::CAdmin(const std::string& username, const std::string& password)
    : CUser(username, password) {}

// Додавання товару
void CAdmin::addProductToCatalog(Catalog& catalog, const CProduct& product) {
    catalog.addProduct(product);
    std::cout << "Product added successfully!\n";
}

// Видалення товару
void CAdmin::removeProductFromCatalog(Catalog& catalog, int productId) {
    if (catalog.removeProduct(productId)) {
        std::cout << "Product removed successfully!\n";
    } else {
        std::cout << "Product not found!\n";
    }
}

// Редагування товару
void CAdmin::editProductInCatalog(Catalog& catalog, int productId, double newPrice, int newQuantity) {
    CProduct* product = catalog.findProduct(productId);
    if (product) {
        product->setPrice(newPrice);
        product->setQuantity(newQuantity);
        std::cout << "Product updated successfully!\n";
    } else {
        std::cout << "Product not found!\n";
    }
}
void CAdmin::showAdminMenu(Catalog& catalog) {
    int choice;
    do {
        std::cout << "\n=== ADMIN MENU ==="
                  << "\n1. Add product"
                  << "\n2. Remove product"
                  << "\n3. Edit product"
                  << "\n4. View all products"
                  << "\n0. Exit"
                  << "\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
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

                addProductToCatalog(catalog, CProduct(id, name, price, quantity));
                catalog.saveToFile();
                break;
            }
            case 2: {
                int productId;
                std::cout << "Enter product ID to remove: ";
                std::cin >> productId;
                removeProductFromCatalog(catalog, productId);
                catalog.saveToFile();
                break;
            }
            case 3: {
                int productId, newQuantity;
                double newPrice;
                std::cout << "Enter product ID to edit: ";
                std::cin >> productId;
                std::cout << "Enter new price: ";
                std::cin >> newPrice;
                std::cout << "Enter new quantity: ";
                std::cin >> newQuantity;

                editProductInCatalog(catalog, productId, newPrice, newQuantity);
                catalog.saveToFile();
                break;
            }
            case 4:
                catalog.printAllProducts();
                break;
            case 0:
                std::cout << "Exiting admin menu...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}
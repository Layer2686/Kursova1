#include "Catalog.h"
#include <algorithm>
#include <sstream>

void Catalog::loadFromFile()
{
    std::ifstream file(filename);
    if (!file.is_open()) return;

    products.clear();
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        int id, quantity;
        double price;
        std::string name;

        // Читаємо ID, ціну та кількість
        ss >> id >> price >> quantity;

        // Читаємо всю решту рядка як назву (включаючи пробіли)
        std::getline(ss >> std::ws, name); // std::ws ігнорує початкові пробіли

        if (!name.empty())
        {
            products.emplace_back(id, name, price, quantity);
        }
    }
    file.close();
}

void Catalog::saveToFile()
{
    std::ofstream file(filename);
    for (const auto& product : products)
    {
        file << product.getId() << " "
             << product.getPrice() << " "
             << product.getQuantity() << " "
             << product.getName() << "\n";
    }
    file.close();
}

void Catalog::addProduct(const CProduct& product)
{
    products.push_back(product);
}

bool Catalog::removeProduct(int productId)
{
    auto it = std::remove_if(products.begin(), products.end(),
        [productId](const CProduct& p) { return p.getId() == productId; });

    if (it != products.end())
    {
        products.erase(it, products.end());
        return true;
    }
    return false;
}

void Catalog::printAllProducts() const
{
    for (const auto& product : products)
    {
        product.printInfo();
    }
}

CProduct* Catalog::findProduct(int productId)
{
    for (auto& product : products)
    {
        if (product.getId() == productId)
        {
            return &product;
        }
    }
    return nullptr;
}
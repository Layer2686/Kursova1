#pragma once
#include "CProduct.hpp"
#include <vector>
#include <fstream>

class Catalog {
private:
    std::vector<CProduct> products;
    const std::string filename = "products.txt";

public:
    void loadFromFile();
    void saveToFile();

    void addProduct(const CProduct& product);
    bool removeProduct(int productId);
    void printAllProducts() const;
    CProduct* findProduct(int productId);
};

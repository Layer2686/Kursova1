#pragma once
#include "CUser.hpp"
#include "Catalog.hpp"

class CAdmin : public CUser {
public:
    CAdmin(const std::string& username, const std::string& password);
    void showMenu() override;

private:
    void addProduct(Catalog& catalog);
    void removeProduct(Catalog& catalog);
    void editProduct(Catalog& catalog);
    void viewAllProducts(Catalog& catalog);
};

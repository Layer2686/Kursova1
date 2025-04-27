#pragma once
#include "CUser.h"
#include "Catalog.h"
#include <vector>

class CBuyer : public CUser {
public:
    CBuyer(const std::string& username, const std::string& password);
    void showMenu() override;

private:
    std::vector<int> cart;
    void viewProducts(Catalog& catalog);
    void addToCart(Catalog& catalog);
    void viewCart(Catalog& catalog);
    void checkout(Catalog& catalog);
};
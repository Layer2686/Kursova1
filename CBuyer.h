#pragma once
#include "CUser.h"
#include "Catalog.h"
#include <algorithm>
#include <vector>
#include <utility> // для std::pair

class CBuyer : public CUser {
public:
    CBuyer(const std::string& username, const std::string& password);
    void showMenu() override;

private:
    std::vector<std::pair<int, int>> cart; // pair<productId, quantity>
    void viewProducts(Catalog& catalog);
    void addToCart(Catalog& catalog);
    void viewCart(Catalog& catalog);
    void checkout(Catalog& catalog);
    void removeFromCart(Catalog& catalog);
};
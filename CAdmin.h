#pragma once
#include "CUser.h"
#include "Catalog.h"
#include "CProduct.h"

class CAdmin : public CUser {
public:
    CAdmin(const std::string& username, const std::string& password);

    void addProductToCatalog(Catalog& catalog, const CProduct& product);
    void removeProductFromCatalog(Catalog& catalog, int productId);
    void editProductInCatalog(Catalog& catalog, int productId, double newPrice, int newQuantity);
    void showAdminMenu(Catalog& catalog);
};
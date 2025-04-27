#include "CAdmin.h"
#include "Catalog.h"

int main() {
    Catalog catalog;
    catalog.loadFromFile(); // Завантажуємо товари при старті

    CAdmin admin("admin", "admin123");
    admin.showAdminMenu(catalog); // Запускаємо меню

    return 0;
}
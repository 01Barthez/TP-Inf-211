#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <uuid/uuid.h>

class Product {
private:
    std::string id;
    std::string name;
    double price;
    int quantity;
    int minQuantity;
    std::string category;

    static std::string generateUUID() {
        uuid_t uuid;
        uuid_generate(uuid);
        char uuid_str[37];
        uuid_unparse_lower(uuid, uuid_str);
        return std::string(uuid_str);
    }

public:
    Product(const std::string& name, double price, int quantity, 
            int minQuantity, const std::string& category)
        : name(name), price(price), quantity(quantity), 
          minQuantity(minQuantity), category(category) {
        if (name.empty() || price <= 0 || quantity < 0 || category.empty()) {
            throw std::invalid_argument("All required fields must be provided!");
        }
        id = generateUUID();
    }

    void getProductInfos() const {
        std::cout << "\nProduct Infos:\n"
                  << "-----------------\n"
                  << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Price: " << price << " Francs\n"
                  << "Quantity: " << quantity << "\n"
                  << "Minimal Quantity: " << minQuantity << "\n"
                  << "Category: " << category << "\n" << std::endl;
    }

    void updateProduct(const std::string& newName = "", double newPrice = -1,
                      int newQuantity = -1, const std::string& newCategory = "") {
        if (newName.empty() && newPrice < 0 && newQuantity < 0 && newCategory.empty()) {
            throw std::invalid_argument("You have to enter at least one information!");
        }

        if (!newName.empty()) name = newName;
        if (newPrice >= 0) price = newPrice;
        if (newQuantity >= 0) quantity = newQuantity;
        if (!newCategory.empty()) category = newCategory;

        std::cout << "Success Information!" << std::endl;
    }

    void restock(int amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Amount must be positive!");
        }
        quantity += amount;
        std::cout << amount << " units added. New stock: " << quantity << std::endl;
    }

    void addStock(int amount) { quantity += amount; }
    void reduceStock(int amount) { quantity -= amount; }

    bool checkInventory() const {
        bool inStock = quantity > minQuantity;
        std::cout << (inStock ? "Product is in stock!" : "Product is not in stock!") << std::endl;
        return inStock;
    }

    // Getters
    const std::string& getId() const { return id; }
    int getQuantity() const { return quantity; }
};

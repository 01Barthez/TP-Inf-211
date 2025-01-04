#pragma once
#include "Person.hpp"
#include "Supermarket.hpp"
#include <vector>
#include <memory>

class Supplier : public Person {
private:
    std::vector<std::shared_ptr<Product>> productsSupplied;

public:
    Supplier(const std::string& name, const std::string& contactInfo, const std::string& gender)
        : Person(name, contactInfo, gender) {}

    void addSupplier(std::shared_ptr<Supermarket> supermarket) {
        supermarket->addSupplier(std::make_shared<Supplier>(*this));
        std::cout << "Supplier \"" << name << "\" added to supermarket \"" 
                  << supermarket->getName() << "\"." << std::endl;
    }

    void getSupplierInfos() const {
        std::cout << "\nSupplier Infos:\n"
                  << "-----------------\n"
                  << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Contact Info: " << contactInfo << "\n"
                  << "Gender: " << gender << "\n"
                  << "Products Supplied: " << productsSupplied.size() << "\n" << std::endl;
    }

    void supplyProduct(std::shared_ptr<Supermarket> supermarket, const std::string& productId, int quantity) {
        if (!supermarket || productId.empty() || quantity <= 0) {
            throw std::invalid_argument("All required information should be provided!");
        }

        auto products = supermarket->getProducts();
        auto it = std::find_if(products.begin(), products.end(),
            [&productId](const std::shared_ptr<Product>& p) { return p->getId() == productId; });

        if (it == products.end()) {
            throw std::runtime_error("Product not found!");
        }

        (*it)->addStock(quantity);
        productsSupplied.push_back(*it);
        
        std::cout << quantity << " Products of ID \"" << productId 
                  << "\" has been successfully supplied!" << std::endl;
    }
};


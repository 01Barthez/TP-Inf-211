#pragma once
#include "Person.hpp"
#include "Supermarket.hpp"
#include <vector>
#include <memory>
#include <ctime>

class Customer : public Person {
private:
    std::vector<std::string> orderHistory;

public:
    Customer(const std::string& name, const std::string& contactInfo, const std::string& gender)
        : Person(name, contactInfo, gender) {}

    void addCustomer(std::shared_ptr<Supermarket> supermarket) {
        supermarket->addCustomer(std::make_shared<Customer>(*this));
        std::cout << "Customer \"" << name << "\" added to supermarket \"" 
                  << supermarket->getName() << "\"." << std::endl;
    }

    void getCustomerInfos() const {
        std::cout << "\nCustomer Infos:\n"
                  << "-----------------\n"
                  << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Contact Info: " << contactInfo << "\n"
                  << "Gender: " << gender << "\n"
                  << "Order History: " << orderHistory.size() << "\n" << std::endl;
    }

    void placeOrder(std::shared_ptr<Supermarket> supermarket, const std::string& productId, int quantity) {
        if (!supermarket || productId.empty() || quantity <= 0) {
            throw std::invalid_argument("All required information should be provided!");
        }

        auto products = supermarket->getProducts();
        auto it = std::find_if(products.begin(), products.end(),
            [&productId](const std::shared_ptr<Product>& p) { return p->getId() == productId; });

        if (it == products.end()) {
            throw std::runtime_error("Product not found!");
        }

        if ((*it)->getQuantity() < quantity) {
            throw std::runtime_error("Insufficient stock!");
        }

        (*it)->reduceStock(quantity);
        
        std::string orderId = generateUUID();
        orderHistory.push_back(orderId);
        
        std::cout << quantity << " Products of ID \"" << productId 
                  << "\" has been successfully ordered!" << std::endl;
    }
};

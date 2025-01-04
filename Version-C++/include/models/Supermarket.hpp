#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Supplier.hpp"
#include "Product.hpp"
#include "Customer.hpp"
#include "Order.hpp"
#include <uuid/uuid.h>

class Supermarket {
private:
    std::string id;
    std::string name;
    std::string location;
    std::string addressInfo;
    std::vector<std::shared_ptr<Supplier>> suppliers;
    std::vector<std::shared_ptr<Product>> products;
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::shared_ptr<Order>> orders;

    static std::string generateUUID() {
        uuid_t uuid;
        uuid_generate(uuid);
        char uuid_str[37];
        uuid_unparse_lower(uuid, uuid_str);
        return std::string(uuid_str);
    }

public:
    Supermarket(const std::string& name, const std::string& location, const std::string& addressInfo)
        : name(name), location(location), addressInfo(addressInfo) {
        if (name.empty() || location.empty() || addressInfo.empty()) {
            throw std::invalid_argument("All required fields must be provided!");
        }
        id = generateUUID();
    }

    void displayInfo() const {
        std::cout << "\nSupermarket Infos:\n"
                  << "-----------------\n"
                  << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Location: " << location << "\n"
                  << "Address Info: " << addressInfo << "\n"
                  << "Suppliers: " << suppliers.size() << "\n"
                  << "Products: " << products.size() << "\n"
                  << "Customers: " << customers.size() << "\n"
                  << "Orders: " << orders.size() << "\n" << std::endl;
    }

    // Getters for private members
    const std::vector<std::shared_ptr<Supplier>>& getSuppliers() const { return suppliers; }
    const std::vector<std::shared_ptr<Product>>& getProducts() const { return products; }
    const std::vector<std::shared_ptr<Customer>>& getCustomers() const { return customers; }
    const std::vector<std::shared_ptr<Order>>& getOrders() const { return orders; }
    const std::string& getName() const { return name; }

    // Methods to add items
    void addSupplier(std::shared_ptr<Supplier> supplier) { suppliers.push_back(supplier); }
    void addProduct(std::shared_ptr<Product> product) { products.push_back(product); }
    void addCustomer(std::shared_ptr<Customer> customer) { customers.push_back(customer); }
    void addOrder(std::shared_ptr<Order> order) { orders.push_back(order); }
};

#pragma once
#include <string>
#include <memory>
#include <ctime>
#include <uuid/uuid.h>

class Order {
private:
    std::string id;
    std::string customerId;
    std::string productId;
    int quantity;
    std::time_t date;

    static std::string generateUUID() {
        uuid_t uuid;
        uuid_generate(uuid);
        char uuid_str[37];
        uuid_unparse_lower(uuid, uuid_str);
        return std::string(uuid_str);
    }

public:
    Order(const std::string& customerId, const std::string& productId, int quantity)
        : customerId(customerId), productId(productId), quantity(quantity) {
        if (customerId.empty() || productId.empty() || quantity <= 0) {
            throw std::invalid_argument("All required fields must be provided!");
        }
        id = generateUUID();
        date = std::time(nullptr);
    }

    void createOrder(std::shared_ptr<Supermarket> supermarket) {
        supermarket->addOrder(std::make_shared<Order>(*this));
        std::cout << "Order successfully added to supermarket \"" 
                  << supermarket->getName() << "\"!" << std::endl;
    }

    void getOrderInfos() const {
        std::cout << "\nOrder Infos:\n"
                  << "-----------------\n"
                  << "ID: " << id << "\n"
                  << "Customer ID: [ " << customerId << " ]\n"
                  << "Product ID: [ " << productId << " ]\n"
                  << "Quantity: " << quantity << "\n" << std::endl;
    }

    void processOrder(std::shared_ptr<Supermarket> supermarket) {
        auto products = supermarket->getProducts();
        auto it = std::find_if(products.begin(), products.end(),
            [this](const std::shared_ptr<Product>& p) { return p->getId() == this->productId; });

        if (it != products.end()) {
            (*it)->reduceStock(quantity);
            std::cout << "Order has been placed successfully!" << std::endl;
        }
    }

    const std::string& getId() const { return id; }
};

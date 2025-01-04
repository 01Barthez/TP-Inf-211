#include "models/Supermarket.hpp"
#include "models/Supplier.hpp"
#include "models/Customer.hpp"
#include "models/Product.hpp"
#include "models/Order.hpp"
#include <iostream>
#include <memory>

int main() {
    try {
        // Create instances and test functionality
        auto dovv = std::make_shared<Supermarket>("DOVV", "Odza B10", "dovv-suppermaket@store.cm");
        dovv->displayInfo();

        auto product = std::make_shared<Product>("Savon", 400, 100, 10, "Domestique");
        product->restock(20);
        product->checkInventory();
        dovv->addProduct(product);

        auto supplier = std::make_shared<Supplier>("Supplier A", "supplierA@example.com", "Male");
        supplier->getSupplierInfos();
        supplier->addSupplier(dovv);

        auto customer = std::make_shared<Customer>("Customer B", "customer@example.com", "Female");
        customer->getCustomerInfos();
        customer->addCustomer(dovv);

        auto order = std::make_shared<Order>("CustomerID123", "ProductID456", 10);
        order->getOrderInfos();
        order->createOrder(dovv);
        order->processOrder(dovv);

        std::cout << "\n\n";
        std::cout << "End of my tests !!! 😄️";	
   }
}

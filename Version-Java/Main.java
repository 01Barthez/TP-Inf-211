package com.supermarket;

import models.*;

public class Main {
    public static void main(String[] args) {
        try {
            // Create instances and test functionality
            Supermarket dovv = new Supermarket("DOVV", "Odza B10", "dovv-suppermaket@store.cm");
            dovv.displayInfo();

            Product product = new Product("Savon", 400, 100, 10, "Domestique");
            product.restock(20);
            product.checkInventory();
            dovv.getProducts().add(product);

            Supplier supplier = new Supplier("Supplier A", "supplierA@example.com", "Male");
            supplier.getSupplierInfos();
            supplier.addSupplier(dovv);

            Customer customer = new Customer("Customer B", "customer@example.com", "Female");
            customer.getCustomerInfos();
            customer.addCustomer(dovv);

            Order order = new Order("CustomerID123", "ProductID456", 10);
            order.getOrderInfos();
            order.createOrder(dovv);
            order.processOrder(dovv);
            order.cancelOrder(dovv);

            System.out.println("\n\nEnd of my tests !!! 😄️\n\n");
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}

package models;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class Supermarket {
    private final String id;
    private final String name;
    private final String location;
    private final String addressInfo;
    private final List<Supplier> suppliers;
    private final List<Product> products;
    private final List<Customer> customers;
    private final List<Order> orders;

    public Supermarket(String name, String location, String addressInfo) {
        if (name == null || location == null || addressInfo == null ||
            name.isEmpty() || location.isEmpty() || addressInfo.isEmpty()) {
            throw new IllegalArgumentException("All required fields must be provided!");
        }

        this.id = UUID.randomUUID().toString();
        this.name = name;
        this.location = location;
        this.addressInfo = addressInfo;
        this.suppliers = new ArrayList<>();
        this.products = new ArrayList<>();
        this.customers = new ArrayList<>();
        this.orders = new ArrayList<>();
    }

    public void displayInfo() {
        System.out.printf("""
            
            Supermarket Infos:
            -----------------
            
            ID: %s
            Name: %s
            Location: %s
            Address Info: %s
            Suppliers: %d
            Products: %d
            Customers: %d
            Orders: %d
            
            """,
            id, name, location, addressInfo,
            suppliers.size(), products.size(), customers.size(), orders.size()
        );
    }

    // Getters
    public String getName() { return name; }
    public List<Supplier> getSuppliers() { return suppliers; }
    public List<Product> getProducts() { return products; }
    public List<Customer> getCustomers() { return customers; }
    public List<Order> getOrders() { return orders; }
}

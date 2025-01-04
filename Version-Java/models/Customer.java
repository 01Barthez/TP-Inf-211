package models;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class Customer extends Person {
    private final List<String> orderHistory;

    public Customer(String name, String contactInfo, String gender) {
        super(name, contactInfo, gender);
        this.orderHistory = new ArrayList<>();
    }

    public void addCustomer(Supermarket supermarket) {
        supermarket.getCustomers().add(this);
        System.out.printf("Customer \"%s\" added to supermarket \"%s\".%n",
                name, supermarket.getName());
    }

    public void getCustomerInfos() {
        System.out.printf("""
            
            Customer Infos:
            -----------------
            
            ID: %s
            Name: %s
            Contact Info: %s
            Gender: %s
            Order History: %d
            
            """,
            id, name, contactInfo, gender, orderHistory.size()
        );
    }

    public void placeOrder(Supermarket supermarket, String productId, int quantity) {
        if (supermarket == null || productId == null || productId.isEmpty() || quantity <= 0) {
            throw new IllegalArgumentException("All required information should be provided!");
        }

        Product product = supermarket.getProducts().stream()
                .filter(p -> p.getId().equals(productId))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("Product not found!"));

        if (product.getQuantity() < quantity) {
            throw new IllegalArgumentException("Insufficient stock!");
        }

        product.reduceStock(quantity);
        String orderId = UUID.randomUUID().toString();
        orderHistory.add(orderId);
        System.out.printf("%d Products of ID \"%s\" has been successfully ordered!%n",
                quantity, productId);
    }
}

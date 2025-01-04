package models;

import java.time.LocalDateTime;
import java.util.UUID;

public class Order {
    private final String id;
    private final String customerId;
    private final String productId;
    private final int quantity;
    private final LocalDateTime date;

    public Order(String customerId, String productId, int quantity) {
        if (customerId == null || productId == null ||
            customerId.isEmpty() || productId.isEmpty() || quantity <= 0) {
            throw new IllegalArgumentException("All required fields must be provided!");
        }

        this.id = UUID.randomUUID().toString();
        this.customerId = customerId;
        this.productId = productId;
        this.quantity = quantity;
        this.date = LocalDateTime.now();
    }

    public void createOrder(Supermarket supermarket) {
        supermarket.getOrders().add(this);
        System.out.printf("Order successful added to supermarket \"%s\"!%n",
                supermarket.getName());
    }

    public void getOrderInfos() {
        System.out.printf("""
            
            Order Infos:
            -----------------
            
            ID: %s
            Customer ID: [ %s ]
            Product ID: [ %s ]
            Quantity: %d
            
            """,
            id, customerId, productId, quantity
        );
    }

    public void processOrder(Supermarket supermarket) {
        Product product = supermarket.getProducts().stream()
                .filter(p -> p.getId().equals(productId))
                .findFirst()
                .orElse(null);

        if (product != null) {
            product.reduceStock(quantity);
            System.out.println("Order has been placed successfully!");
        }
    }

    public void cancelOrder(Supermarket supermarket) {
        supermarket.getOrders().remove(this);
        System.out.println("This order has just successfully been deleted!");
    }
}

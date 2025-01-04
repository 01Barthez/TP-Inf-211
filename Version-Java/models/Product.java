package models;

import java.util.UUID;

public class Product {
    private final String id;
    private String name;
    private double price;
    private int quantity;
    private final int minQuantity;
    private String category;

    public Product(String name, double price, int quantity, int minQuantity, String category) {
        if (name == null || category == null || name.isEmpty() || category.isEmpty() ||
            price <= 0 || quantity < 0) {
            throw new IllegalArgumentException("All required fields must be provided!");
        }

        this.id = UUID.randomUUID().toString();
        this.name = name;
        this.price = price;
        this.quantity = quantity;
        this.minQuantity = minQuantity;
        this.category = category;
    }

    public void getProductInfos() {
        System.out.printf("""
            
            Product Infos:
            -----------------
            
            ID: %s
            Name: %s
            Price: %.2f Francs
            Quantity: %d
            Minimal Quantity: %d
            Category: %s
            
            """,
            id, name, price, quantity, minQuantity, category
        );
    }

    public void updateProduct(String newName, Double newPrice, Integer newQuantity, String newCategory) {
        if (newName == null && newPrice == null && newQuantity == null && newCategory == null) {
            throw new IllegalArgumentException("You have to enter at least one information!");
        }

        if (newName != null) name = newName;
        if (newPrice != null) price = newPrice;
        if (newQuantity != null) quantity = newQuantity;
        if (newCategory != null) category = newCategory;

        System.out.println("Success Information!");
    }

    public void restock(int amount) {
        if (amount <= 0) {
            throw new IllegalArgumentException("Amount must be positive!");
        }
        quantity += amount;
        System.out.printf("%d units added. New stock: %d%n", amount, quantity);
    }

    public void addStock(int amount) { quantity += amount; }
    public void reduceStock(int amount) { quantity -= amount; }

    public boolean checkInventory() {
        boolean inStock = quantity > minQuantity;
        System.out.println(inStock ? "Product is in stock!" : "Product is not in stock!");
        return inStock;
    }

    public String getId() { return id; }
    public int getQuantity() { return quantity; }
}

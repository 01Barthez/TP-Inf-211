package models;

import java.util.ArrayList;
import java.util.List;

public class Supplier extends Person {
    private final List<Product> productsSupplied;

    public Supplier(String name, String contactInfo, String gender) {
        super(name, contactInfo, gender);
        this.productsSupplied = new ArrayList<>();
    }

    public void addSupplier(Supermarket supermarket) {
        supermarket.getSuppliers().add(this);
        System.out.printf("Supplier \"%s\" added to supermarket \"%s\".%n",
                name, supermarket.getName());
    }

    public void getSupplierInfos() {
        System.out.printf("""
            
            Supplier Infos:
            -----------------
            
            ID: %s
            Name: %s
            Contact Info: %s
            Gender: %s
            Products Supplied: %d
            
            """,
            id, name, contactInfo, gender, productsSupplied.size()
        );
    }

    public void supplyProduct(Supermarket supermarket, String productId, int quantity) {
        if (supermarket == null || productId == null || productId.isEmpty() || quantity <= 0) {
            throw new IllegalArgumentException("All required information should be provided!");
        }

        Product product = supermarket.getProducts().stream()
                .filter(p -> p.getId().equals(productId))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("Product not found!"));

        product.addStock(quantity);
        productsSupplied.add(product);
        System.out.printf("%d Products of ID \"%s\" has been successfully supplied!%n",
                quantity, productId);
    }
}

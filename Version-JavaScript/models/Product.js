import { v4 as uuidv4 } from 'uuid';

//! Implementation of class and methods for CRUD operations (Create, Read, Update, Delete) for managing products in the system
class Product {
    constructor(name, price, quantity, minQuantity = 0, category) {
        if (!name || !price || !quantity || !category) {
            throw new Error("All required fields must be provided!");
        }

        this.id = uuidv4();
        this.name = name;
        this.price = price;
        this.quantity = quantity;
        this.minQuantity = minQuantity;
        this.category = category;
    }

	//! Method to Add a new product to the inventory.
	createProduct(supermaket) {
		supermaket.product.push(this);
	
		console.log(`Product successful added to the supermaket "${supermaket.name}" !`);
	};
	
	// Method Retrieve details of a product
	getProductInfos() {
		console.log(`
		Product Infos:
		-----------------
		
		ID: ${this.id}
		Name: ${this.name}
		Price: ${this.price} Francs
		Quantity: ${this.quantity}
		Minimal Quantity: ${this.minQuantity}
		Category: ${this.category}
		`);
	};
	
	//! Method to Update the details (price or quantity) of a product. 
	updateProduct(newName, newPrice, newQuantity, newCategory) { // jsut one argument is necessary, the rest is optional here...
        if(!newName && !newPrice && !newQuantity && !newCategory)
        	throw new Error("y've to enter at less one information !!!");
        	
        if(newName) this.name = newName;
    	if(newPrice) this.price = newPrice
    	if(newQuantity) this.quantity = newQuantity
    	if(newCategory) this.category = newCategory
    	
    	console.log("Success Information !");
    }

	//! Method to Remove a product from the inventory.
	deleteProduct(supermaket) {
		supermaket.products = supermaket.products.filter(product => product.id !== this.id);
		
		console.log(`This product has just successfully been deleted!`);
	};
	
    restock(quantity) {
        this.quantity += quantity;
        console.log(`${quantity} units added. New stock: ${this.quantity}`);
    };
    
    //! Method to Check if a product is in stock
	checkInventory() {
		if(this.quantity > this.minQuantity) {
			console.log(`Product is on stock !`);
			return true;
		} else {
			console.log(`Product is not on stock !`);
			return false;
		}
	};
}

export default Product;

// Test
const product = new Product("Savon", 400, 100, 10, "Domestique");
// product.getProductInfos();



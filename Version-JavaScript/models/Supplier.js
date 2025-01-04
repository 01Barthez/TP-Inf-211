import Person from './Person.js';

// Class to Manage Supplier who is above all a Person
class Supplier extends Person {
    constructor(name, contactInfo, gender) {
        super(name, contactInfo, gender);
        this.productsSupplied = []; // List of supplied products
    }

	// Add a supplier to inventory of supermaket
    addSupplier(supermarket) {
        supermarket.suppliers.push(this);
        console.log(`Supplier "${this.name}" added to supermarket "${supermarket.name}".`);
    }

	// Method to get Supplier informations
	getSupplierInfos() {
		console.log(`
		Supplier Infos:
		-----------------
		
		ID: ${this.id}
		Name: ${this.name}
		Contact Info: ${this.contactInfo}
		Sexe: ${this.gender}
		Products Supplied: ${this.productsSupplied.length}
		`);
	};
	
	// Method to delete a supplier from a suppermaket
    deleteSupplier(supermarket) {
        supermarket.suppliers = supermarket.suppliers.filter(supplier => supplier.id !== this.id);
        console.log(`Supplier "${this.name}" removed from supermarket "${supermarket.name}".`);
    };
    
    // Method to supply a product depending of the productID and the quantity
	supplyProduct(supermarket, productID, quantity) {
		if(!supermarket, !productID || !quantity) {
			throw new Error("All required informations should be provided !!!");
		}
		
		const product = supermarket.products.find(p => p.id === productID);

        if (!product) throw new Error("Product not found!");
        product.stock += quantity;
		
		this.productsSupplied.push(product);
		
		// Return success message after all
		console.log(`${quantity} Products of ID "${productID}" has been successful supplied !`);
	};
}
export default Supplier;

// Test
const supplier = new Supplier("SupplierA", "supplierA@example.com", "Female");

// supplier.getSupplierInfos();

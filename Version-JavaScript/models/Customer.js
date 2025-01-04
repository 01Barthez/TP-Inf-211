import Person from './Person.js';

// Class to Manage Customer who is above all a Person
class Customer extends Person {
    constructor(name, contactInfo, gender) {
        super(name, contactInfo, gender);
        this.orderHistory = [];
    }

	// Add a Customer to inventory of supermaket
    addCustomer(supermarket) {
        supermarket.customers.push(this);
        console.log(`Customer "${this.name}" added to supermarket "${supermarket.name}".`);
    }

	// Method to get Customer informations
	getCustomerInfos() {
		console.log(`
		Customer Infos:
		-----------------
		
		ID: ${this.id}
		Name: ${this.name}
		Contact Info: ${this.contactInfo}
		Sexe: ${this.gender}
		Order History: ${this.orderHistory.length}
		`);
	}
	
	// Method to delete a Customer from a suppermaket
    deleteCustomer(supermarket) {
        supermarket.customers = supermarket.customers.filter(customer => customer.id !== this.id);
        console.log(`Customer "${this.name}" removed from supermarket "${supermarket.name}".`);
    };
    
    // Method to place an order depending of the productID and the quantity
	placeOrder(supermaket, productID, quantity) {
		if(!supermaket || !productID || !quantity) {
			throw new Error("All required informations should be provided !!!");
		}
		
		const product = supermaket.products.find(p => p.id === productID);
        if (!product) throw new Error("Product not found!");
        
        
        if (product.stock < quantity) throw new Error("Insufficient stock!");

        product.stock -= quantity;
        
		 const order = {
            id: uuidv4(),
            customerId: this.id,
            productID,
            quantity,
            date: new Date(),
        };
		
		this.orderHistory.push(order.id);
		
		// Return success message after all
		console.log(`${quantity} Products of ID "${productID}" has been successful supplied !`);
	};
}

export default Customer;

// Test
const customer = new Customer("Customer B", "customer@example.com", "Female");
// customer.getCustomerInfos();

import { v4 as uuidv4 } from 'uuid';

// Implementation of class and methods for placing and managing customer orders
class Order {
    constructor(customerId, productId, quantity) {
        if (!customerId || !productId || !quantity) {
            throw new Error("All required fields must be provided!");
        }

        this.id = uuidv4();
        this.customerId = customerId;
        this.productId = productId;
        this.quantity = quantity;
        this.date = new Date();
    }
    
    //! Method to Add a new product to the inventory.
	createOrder(supermaket) {
		supermaket.products.push(this);
	
		console.log(`Product successful added to the supermaket "${supermaket.name}" !`);
	};
	
	// Method Retrieve details of a product
	getOrderInfos() {
		console.log(`
		Order Infos:
		-----------------
		
		ID: ${this.id}
		Customer ID: [ ${this.customerId} ]
		Product ID: [ ${this.productID} ]
		Quantity: ${this.quantity}
		`);
	};

	//! Allow an order to be canceled, and restore the stock
	cancelOrder(supermaket) {
		supermaket.orders = supermaket.orders.filter(order => order.id !== this.id);
		
		console.log(`This order has just successfully been deleted!`);
	};
	
	//! Update the stock (reduce quantity) when an order is placed.
	processOrder(supermaket) {
		const product = supermaket.products.filter(product => product.id !== this.productId);
		product.quantity -= this.quantity; 
		
		console.log(`Order have been placed succefully !`);
	}
}

export default Order;

// Test
const order = new Order("CustomerID123", "ProductID456", 10);
// order.getOrderInfos();


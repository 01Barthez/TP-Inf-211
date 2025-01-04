import { v4 as uuidv4 } from 'uuid';

// Class to manage Suppermaket
class Supermarket {
    constructor(name, location, addressInfo, suppliers = [], products = [], customers = [], orders = []){
		if(!name || !location || !addressInfo) {
		 throw new Error ("All required fields most be provided !!!");
		}
		
		this.id = uuidv4();
		this.name = name;
		this.location = location;
		this.addressInfo = addressInfo;
		this.suppliers = suppliers; // List of supplier if provided
		this.products = products; // list of product if provided
		this.customers = customers; // list of customer if provided
		this.orders = orders; // list of order if provided
	}

	// Method to get Suppermaket information
    displayInfo() {
        console.log(`
        Supermarket Infos:
        -----------------
        
        ID: ${this.id}
        Name: ${this.name}
        Location: ${this.location}
        Address Info: ${this.addressInfo}
        Suppliers: ${this.suppliers.length}
        Products: ${this.products.length}
        Customers: ${this.customers.length}
        Orders: ${this.orders.length}
        `);
    }
}

export default Supermarket;

// Test
const market = new Supermarket("DOVV", "Odza B10", "dovv-suppermaket@store.cm");
// market.displayInfo();

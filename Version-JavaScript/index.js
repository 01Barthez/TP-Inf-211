import Supermarket from './models/Supermarket.js';
import Supplier from './models/Supplier.js';
import Customer from './models/Customer.js';
import Product from './models/Product.js';
import Order from './models/Order.js';

// Create instances and test functionality
const dovv = new Supermarket("DOVV", "Odza B10", "dovv-suppermaket@store.cm");
dovv.displayInfo();

const product = new Product("Savon", 400, 100, 10, "Domestique");
product.restock(20);
product.checkInventory();

const supplier = new Supplier("Supplier A", "supplierA@example.com", "Male");
supplier.getSupplierInfos();
supplier.addSupplier(dovv);


const customer = new Customer("Customer B", "customer@example.com", "Female");
customer.getCustomerInfos();
customer.addCustomer(dovv);
// customer.placeOrder(dovv, "productId", 2);

const order = new Order("CustomerID123", "ProductID456", 10);
order.getOrderInfos();
order.createOrder(dovv);
order.processOrder(dovv);
order.cancelOrder(dovv);


console.log();
console.log();
console.log("End of my tests !!! 😄️");
console.log();
console.log();

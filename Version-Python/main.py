from models.supermarket import Supermarket
from models.supplier import Supplier
from models.customer import Customer
from models.product import Product
from models.order import Order

def main():
    # Create instances and test functionality
    dovv = Supermarket("DOVV", "Odza B10", "dovv-suppermaket@store.cm")
    dovv.display_info()

    product = Product("Savon", 400, 100, 10, "Domestique")
    product.restock(20)
    product.check_inventory()

    supplier = Supplier("Supplier A", "supplierA@example.com", "Male")
    supplier.get_supplier_infos()
    supplier.add_supplier(dovv)

    customer = Customer("Customer B", "customer@example.com", "Female")
    customer.get_customer_infos()
    customer.add_customer(dovv)

    order = Order("CustomerID123", "ProductID456", 10)
    order.get_order_infos()
    order.create_order(dovv)
    order.process_order(dovv)
    order.cancel_order(dovv)

    print("\n\n")
    print("End of my tests !!! 😄️")
    print("\n\n")

if __name__ == "__main__":
    main()

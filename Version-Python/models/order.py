from uuid import uuid4
from datetime import datetime

class Order:
    def __init__(self, customer_id, product_id, quantity):
        if not all([customer_id, product_id, quantity]):
            raise ValueError("All required fields must be provided!")

        self.id = str(uuid4())
        self.customer_id = customer_id
        self.product_id = product_id
        self.quantity = quantity
        self.date = datetime.now()

    def create_order(self, supermarket):
        supermarket.orders.append(self)
        print(f'Order successful added to the supermarket "{supermarket.name}"!')

    def get_order_infos(self):
        print(f"""
        Order Infos:
        -----------------
        
        ID: {self.id}
        Customer ID: [ {self.customer_id} ]
        Product ID: [ {self.product_id} ]
        Quantity: {self.quantity}
        """)

    def cancel_order(self, supermarket):
        supermarket.orders = [o for o in supermarket.orders if o.id != self.id]
        print("This order has just successfully been deleted!")

    def process_order(self, supermarket):
        product = next((p for p in supermarket.products if p.id == self.product_id), None)
        if product:
            product.quantity -= self.quantity
            print("Order have been placed successfully!")

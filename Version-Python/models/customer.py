from uuid import uuid4
from .person import Person

class Customer(Person):
    def __init__(self, name, contact_info, gender):
        super().__init__(name, contact_info, gender)
        self.order_history = []

    def add_customer(self, supermarket):
        supermarket.customers.append(self)
        print(f'Customer "{self.name}" added to supermarket "{supermarket.name}".')

    def get_customer_infos(self):
        print(f"""
        Customer Infos:
        -----------------
        
        ID: {self.id}
        Name: {self.name}
        Contact Info: {self.contact_info}
        Sexe: {self.gender}
        Order History: {len(self.order_history)}
        """)

    def delete_customer(self, supermarket):
        supermarket.customers = [c for c in supermarket.customers if c.id != self.id]
        print(f'Customer "{self.name}" removed from supermarket "{supermarket.name}".')

    def place_order(self, supermarket, product_id, quantity):
        if not all([supermarket, product_id, quantity]):
            raise ValueError("All required information should be provided!")

        product = next((p for p in supermarket.products if p.id == product_id), None)
        if not product:
            raise ValueError("Product not found!")
        
        if product.quantity < quantity:
            raise ValueError("Insufficient stock!")

        product.quantity -= quantity
        
        order = {
            'id': str(uuid4()),
            'customer_id': self.id,
            'product_id': product_id,
            'quantity': quantity,
            'date': datetime.now()
        }
        
        self.order_history.append(order['id'])
        print(f'{quantity} Products of ID "{product_id}" has been successful supplied!')

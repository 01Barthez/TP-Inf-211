from uuid import uuid4

class Product:
    def __init__(self, name, price, quantity, min_quantity=0, category=None):
        if not all([name, price, quantity, category]):
            raise ValueError("All required fields must be provided!")

        self.id = str(uuid4())
        self.name = name
        self.price = price
        self.quantity = quantity
        self.min_quantity = min_quantity
        self.category = category

    def create_product(self, supermarket):
        supermarket.products.append(self)
        print(f'Product successful added to the supermarket "{supermarket.name}"!')

    def get_product_infos(self):
        print(f"""
        Product Infos:
        -----------------
        
        ID: {self.id}
        Name: {self.name}
        Price: {self.price} Francs
        Quantity: {self.quantity}
        Minimal Quantity: {self.min_quantity}
        Category: {self.category}
        """)

    def update_product(self, new_name=None, new_price=None, new_quantity=None, new_category=None):
        if not any([new_name, new_price, new_quantity, new_category]):
            raise ValueError("You have to enter at least one information!")
            
        if new_name:
            self.name = new_name
        if new_price:
            self.price = new_price
        if new_quantity:
            self.quantity = new_quantity
        if new_category:
            self.category = new_category
            
        print("Success Information!")

    def delete_product(self, supermarket):
        supermarket.products = [p for p in supermarket.products if p.id != self.id]
        print("This product has just successfully been deleted!")

    def restock(self, quantity):
        self.quantity += quantity
        print(f"{quantity} units added. New stock: {self.quantity}")

    def check_inventory(self):
        if self.quantity > self.min_quantity:
            print("Product is on stock!")
            return True
        else:
            print("Product is not on stock!")
            return False

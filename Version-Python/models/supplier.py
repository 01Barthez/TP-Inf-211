from .person import Person

class Supplier(Person):
    def __init__(self, name, contact_info, gender):
        super().__init__(name, contact_info, gender)
        self.products_supplied = []

    def add_supplier(self, supermarket):
        supermarket.suppliers.append(self)
        print(f'Supplier "{self.name}" added to supermarket "{supermarket.name}".')

    def get_supplier_infos(self):
        print(f"""
        Supplier Infos:
        -----------------
        
        ID: {self.id}
        Name: {self.name}
        Contact Info: {self.contact_info}
        Sexe: {self.gender}
        Products Supplied: {len(self.products_supplied)}
        """)

    def delete_supplier(self, supermarket):
        supermarket.suppliers = [s for s in supermarket.suppliers if s.id != self.id]
        print(f'Supplier "{self.name}" removed from supermarket "{supermarket.name}".')

    def supply_product(self, supermarket, product_id, quantity):
        if not all([supermarket, product_id, quantity]):
            raise ValueError("All required information should be provided!")

        product = next((p for p in supermarket.products if p.id == product_id), None)
        if not product:
            raise ValueError("Product not found!")

        product.quantity += quantity
        self.products_supplied.append(product)
        print(f'{quantity} Products of ID "{product_id}" has been successful supplied!')

from uuid import uuid4

class Supermarket:
    def __init__(self, name, location, address_info, suppliers=None, products=None, customers=None, orders=None):
        if not all([name, location, address_info]):
            raise ValueError("All required fields must be provided!")
            
        self.id = str(uuid4())
        self.name = name
        self.location = location
        self.address_info = address_info
        self.suppliers = suppliers or []
        self.products = products or []
        self.customers = customers or []
        self.orders = orders or []

    def display_info(self):
        print(f"""
        Supermarket Infos:
        -----------------
        
        ID: {self.id}
        Name: {self.name}
        Location: {self.location}
        Address Info: {self.address_info}
        Suppliers: {len(self.suppliers)}
        Products: {len(self.products)}
        Customers: {len(self.customers)}
        Orders: {len(self.orders)}
        """)

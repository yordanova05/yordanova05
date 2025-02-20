class AutoHouse:
    def __init__(self,name, started_year):
        self.name = name
        self.started_year = started_year
        self.brands = []
        self.cars = []
        self.employees = []
        self.managers = []
        self.clients = []
        self.bank = 10000
        
    def __str__(self):
        return f"Autohouse \"{self.year}\" - {self.year} year"
    
    def house_info(self):
        return f"\"{self.name}\" was created {self.started_year} year!"
    
    def add_auto(self, car):
        if not car.brand in self.brands:
            self.brands.append(car.brand) 
        self.cars.append(car)
        return f"{car.brand} {car.model} - {car.year} was added succesfully!"
    
    def sell_car(self,car, client):
        if car in self.cars:
            if (car.month_price/client.salary) < 35/100:
                client.deposit = car.final_price
                self.cars.remove(car)
                client.purchases.append(car)
                return f"{car} was salled succesfully "
            else:
                return "You can't buy this car!"
            
    def add_employee(self, employee):
        if employee not in self.employees: 
            self.employees.append(employee) 
            if employee.status.lower() == "manager":
                if employee not in self.managers:
                    self.managers.append(employee)
            return f"Employee {employee.fname} added successfully."
        return f"Employee {employee.fname} is already in the list."
            
    def add_client(self,client):
        if not client in self.clients:
            self.clients.append(client) 
            return "New client added!"   
        
    def paying_client(self, client, money):
        if client in self.clients:
            self.bank += money
            client.deposit -= money
            if client.deposit == 0:
                return "All paid!"
            elif client.deposit < 0:
                client.deposit = 0
                cash = abs(client.deposit)
                return f"Your exchange - {cash}"
            else:
                return f"({client.id}) {client.deposit}$ remaining"
        else:
            return "This client doesn't exist!"
        
    def show_managers(self):
        if self.managers:
            for person in self.managers:
                print(person)
        else:
            return "The only manager is the boss!"   
        
    def show_employees(self):
        if self.employees:
            for employee in self.employees:
                print(employee)
        else:
            return "Out of employees!"
        return "---"
     
    def show_cars(self):
        if self.cars:
            for car in self.cars:
                print(car)
        else:
            return "Out of cars!"
        return "---"      
    
    def show_brands(self):
        if self.brands:
            for brand in self.brands:
                print(brand, end=", ")
        else:
            return "Out of cars!"
                
    def show_clients(self):
        if self.clients:
            for client in self.clients:
                print(client)
        else:
            return "Out of clients!"
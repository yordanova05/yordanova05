class Client:
    def __init__(self, id, fname, mname, lname, salary):
        self.id = id
        self.fname = fname
        self.mname = mname
        self.lname = lname
        self.salary = salary
        self.deposit = 0
        self.purchases = []
        
    def __str__(self):
        return f"({self.id}) {self.fname} {self.lname}, - {self.deposit}$"
    
    def info(self):
        return f"(client) Id: {self.id} {self.fname} {self.lname}, - {self.deposit}$"
    
    def show_balance(self):
        return f"Your balance: {self.deposit}"
    
    def show_purchases(self):
        if self.purchases:
            for x in self.purchases:
                print(x)
        else:
            return "Not having purchases yet!"
    
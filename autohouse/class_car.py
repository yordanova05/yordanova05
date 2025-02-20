class Car:
    def __init__(self, brand, model, year,color,probeg, engine,price, leasing):
        self.brand = brand
        self.model = model
        self.year = year
        self.color = color
        self.probeg = probeg
        self.engine = engine
        self.price = price
        self.leasing = leasing
        self.month_price = 0
        self.final_price = 0
        
    def __str__(self):
        return f"{self.brand} {self.model} ({self.year}) - {self.probeg}km {self.engine}hp ({self.color}) {self.price}$"
    
    def info(self):
        return f"{self.__str__()} leasing - {self.leasing}"
    
    def car_leasing_info(self):
        r = 10/1200
        new_price = self.price + self.leasing*12*10/100
        result = self.price*(r*pow((1 + r),self.leasing*12))/pow((1 + r),self.leasing*12) - 1
        self.month_price = result
        self.final_price = new_price
        return f"For {self.leasing} year(s) (we have interest rate of 10% per year)\n\
- {self.price} -> {round(self.final_price,2)}(with interest rate)\
- {round(result,2)}$ a month"
    
    
    
    
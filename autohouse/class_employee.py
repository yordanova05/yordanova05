class Employee:
    def __init__(self, id, fname, mname, lname, working_years, salary):
        self.id = id
        self.fname = fname
        self.mname = mname
        self.lname = lname
        self.working_years = working_years
        self.salary = salary
        self.status = "employee"
        self.employees = []
        
    def __str__(self):
        return f"{self.id} - {self.fname} {self.mname} {self.lname}, {self.working_years} years - {self.salary}$"
    
    def info(self):
        return f"({self.status}) {self.id} - {self.fname} {self.mname} {self.lname}, {self.working_years} years - {self.salary}$"
    
    @property
    def bonus(self):
        if self.working_years >=5:
            self.salary += 200
            
    def promote(self):
        if self.working_years >= 7:
            self.status = "manager"
            return "Promoted succesfully!"
        else:
            return "Not enough worked years!"

            
            
          
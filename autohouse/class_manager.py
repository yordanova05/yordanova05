from class_employee import Employee
class Manager:
    def __init__(self, person: Employee):
        self.person = person
        
    def __str__(self):
        return f"Manager - {self.person.fname} {self.person.mname} {self.person.lname}, {self.person.lorking_years}\
years - {self.person.salary}$"

    def info(self):
        return f"({self.person.status}) {self.id} {self.person.fname} {self.person.mname} {self.person.lname}, {self.person.lorking_years}\
years - {self.person.salary}$"
        
    
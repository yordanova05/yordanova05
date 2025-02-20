class Person():
    def __init__(self, name, fname, age, nationality):
        self.name = name
        self.familyname = fname
        self.age = age
        self.nat = nationality

    def print(self):
        print(f"Your name is {self.name} {self.familyname} and you are {self.nat}")

class Student(Person):
    def __init__(self, name,fname, age, nationality, uni, year):
        Person.__init__(self, name, fname, age, nationality)
        self.name = name
        self.university = uni
        self.year_of_graduating = year
    
    def printstudent(self):
        print(f"You graduated in {self.year_of_graduating} {self.university}")

class Lecturer(Person):
    def __init__(self, name, fname, age, nationality, uni, experience):
        Person.__init__(self, name, fname, age, nationality)
        self.name= name
        self.fname = fname
        self.uni = uni
        self.exp = experience
    
    def printteacher(self):
        print(f"{self.name} {self.fname} from {self.uni} is {self.exp}")


name = input("Name: ")
fname = input("Familyname: ")
age = int(input("Age: "))
nat = input("Nationality: ")
person1 = Person(name,fname,age,nat)
person1.print()

name = input("Name: ")
fname = input("Familyname: ")
nat = input("nat: ")
person2 = Person(name, fname, age, nat)
person2.print()

person3 = Person("Ivan", "Ivanov", None ,"bulgarian") 
person3.print()
print()

person4 = Student(None, None,None,None,"PMG ""Vasil Drumev""" , 2024)
person4.printstudent()
person4.print()
print()

person5 = Lecturer("Maria", "Ivanova", None, "bulgarian", "Technical Univursety Sofia", "mathematic teacher")
person5.print()
person5.printteacher()
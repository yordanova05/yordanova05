class Animal:
    def __init__(self, name, species, age:int, health:int):
        self.name= name
        self.species = species
        self.age = age
        self.health = health

    def print_info(self):
        print(f"Name: {self.name}, Species: {self.species}, Age: {self.age}, Healh: {self.health}")

    
class Mammal(Animal):
    def __init__(self,name, species, age: int, health:int, fur_color, diet):
        Animal.__init__(self, name, species, age, health)
        self.fur_color = fur_color
        self.diet = diet

    def print_info(self):
        super().print_info()
        print(f"Fur color: {self.fur_color}, Diet: {self.diet}")


class Bird(Animal):
    def __init__(self, name, species, age:int, health:int, wing_span:float, can_fly:bool):
        Animal.__init__(self, name, species, age, health)
        self.wing_span = wing_span
        self.can_fly = can_fly

    def print_info(self):
        super().print_info()
        print(f"Wing span: {self.wing_span}, Can fly: {self.can_fly}")


class Raptile(Animal):
    def __init__(self, name, species, age:int, health:int, is_venoumos:bool, preffered_temperature:float):
        Animal.__init__(self, name, species, age, health)
        self.is_venomous = is_venoumos
        self.temperature = preffered_temperature

    def print_info(self):
        super().print_info()
        print(f"Venomous: {self.is_venomous}, Preffered temperature: {self.temperature}")


class Zoo:
    def __init__(self):
        self.enclosures = {}
        self.species = {"mammal": [],"raptile": [], "bird": []}

    def add_animal(self, animal, enclosures_number):
        if enclosures_number in self.enclosures:
            self.enclosures[enclosures_number].append(animal.name)
        else:
            self.enclosures[enclosures_number] = [animal.name]

        if animal.species.lower() == "mammal":
            self.species["mammal"].append(animal.name)

        elif animal.species.lower() == "raptile":
            self.species["raptile"].append(animal.name)

        elif animal.species.lower() == "bird":
            self.species["bird"].append(animal.name)


    def remove_animal(self, name):
        for k,v in self.enclosures.items():
            if name in self.enclosures[k]:
                for an in v:
                    if an == name:
                        self.enclosures[k].remove(an)
                        return
        print("This animal was not found!")


    def list_animals_in_enclosure(self,num_encosure):
        if self.enclosures[num_encosure] == []:
            print(f"No animals anymore in cell {num_encosure}")
            return
        if num_encosure in self.enclosures:
            items = self.enclosures[num_encosure]
            result = ", ".join(items)
            print(result)
        else:
            print("No animals in this cell!")


    def transfer_animal(self, num_cell_from:int, animal, num_cell_to:int):
        if num_cell_from in self.enclosures:
            if num_cell_to not in self.enclosures:
                self.enclosures[num_cell_to] = []
            items = self.enclosures[num_cell_from]
            for item in items:
                if item == animal:
                    possition = items.index(item)
                    self.enclosures[num_cell_from].pop(possition)
                    self.enclosures[num_cell_to].append(animal)
                    return
                print("Animal doesn't exist in this cell!")

        else:
            print("There is no animals in this cell!")

    
    def find_animals_by_species(self, animal_species):
        for x in self.species.keys():
            if x == animal_species:
                result = ", ".join(self.species[x])
                print(result)
             


animal1 = Raptile("Croccodile", "raptile", 21, 8, False, 18)
animal2 = Mammal("Gazzella", "mammal", 4, 9, "brown", "grass")
animal3 = Bird("Colibry", "bird", 1, 10, 0.8, True)
animal4 = Mammal("Cat", "mammal", 2, 10, "black", "meat")
animal5 = Raptile("Snake", "raptile", 3, 5, True, 27.5)

zoo = Zoo()
zoo.add_animal(animal1,1)
zoo.add_animal(animal2,1)
zoo.add_animal(animal3,2)
zoo.add_animal(animal4,2)
zoo.add_animal(animal5,3)

zoo.remove_animal("Colibry")
zoo.list_animals_in_enclosure(2)
print("-------------")

zoo.list_animals_in_enclosure(1)
print("-------------")

zoo.transfer_animal(1,"Croccodile",3)
zoo.list_animals_in_enclosure(3)
print("-------------")

zoo.transfer_animal(2,"Cat",2)
zoo.list_animals_in_enclosure(2)
print("-------------")

zoo.find_animals_by_species("raptile")
print("------------------------")
zoo.list_animals_in_enclosure(1)
zoo.list_animals_in_enclosure(2)
zoo.list_animals_in_enclosure(3)
print("--------------------------")
zoo.find_animals_by_species("raptile")
zoo.find_animals_by_species("bird")
zoo.find_animals_by_species("mammal")
print("TEST##################")  

zoo.transfer_animal(1,"Gazzella",4)
zoo.list_animals_in_enclosure(1)
zoo.list_animals_in_enclosure(4)




            
        
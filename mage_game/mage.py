import random
class Mage:
    def __init__(self, name, level, mana, health, spells: dict, inventory: list, experience):
        self.name = name 
        self.level = level 
        self.mana = mana
        self.health = health
        self.spells = spells
        self.invetory = inventory
        self.experience = experience
        self.max_health = 100
        self.max_mana = 100
    
    def mage_information(self):
        return(f"name: {self.name}, level: {self.level}, mana: {self.mana}, health: {self.health}\
 spells: {self.spells}, inventory: {self.invetory}, experience: {self.experience}")
        
    def cast_spell(self, spell_name) :
        for k,v in self.spells.items():
            if spell_name == k:
                if self.mana >= v:
                    self.mana -=v
                    return "Cast spell!"
                else: 
                    return "Not enough mana!"
                
    def level_up(self):
        self.level+=1
        bonus_health = self.health*10%100
        bonus_mana= self.mana*10%100
        self.max_health += bonus_health
        self.max_mana += bonus_mana
        
    def gain_experience(self, amount):
        if self.experience + amount >=100:
            self.level_up()
        else:
            self.experience += amount
            
    def add_spell(self, spell_name, mana_cost):
        self.spells[spell_name] = mana_cost
    
    def add_item(self, item):
        self.invetory.append(item)
        
    def remove_item(self, item):
        if item in self.invetory:
            self.invetory.remove(item)
            
    def heal(self, amount):
        if self.health + amount > self.max_health:
            self.health = self.max_health
        else:
            self.health += amount
            
def battle(mage1,mage2):
    while True:
        print(f'{mage1.name} attacks!')
        random_spell1 = random.choice(mage1.spells.keys())
        for k,v in mage1.spells.items():
            if k == random_spell1:
                mage1.mana -= v
                if mage1.mana <= 0:
                    return  f"{mage2.name} wins!"
                
        print(f'{mage2.name} attacks!')
        random_spell2 = random.choice(mage1.spells.keys())
        for k,v in mage2.spells.items():
            if k == random_spell2:
                mage2.mana -= v
                if mage2.mana <= 0:
                    return  f"{mage1.name} wins!"

def find_mage_by_name(mages_list,name):
    for m in mages_list:
        if name == m.name:
            return f"Mage: {m.mage_information()}"
    return "Mage not found"
    
def add_mage(mages_list, mage):
    mages_list.append(mage)
    
def remove_mage(mages_list, mage):
    if mage in mages_list:
        mages_list.remove(mage)
    else: return "Mage not found!"
    
def list_all_mages(mages_list):
    for m in mages_list:
        print(m.mage_information())

            
if __name__ == "__main__":
    mages_list = []
    mage1 = Mage("Witch", 5, 20, 75, {"poison":5}, ["hand of justice", "Rod"], 45)
    mage2 = Mage("Veigar", 15, 93, 55, {"ult":25, "comet":15}, ["Lucky", "AP"], 18)
    
    print(mage1.mage_information())
    print("--------------")
    print(mage1.cast_spell("poison"))
    print("--------------")
    print(mage1.mage_information())
    print("--------------")
    mage1.level_up()
    print(mage1.mage_information())
    print("--------------")
    mage1.gain_experience(100)
    print(mage1.mage_information())
    print("--------------")
    mage1.add_spell("Umami", 50)
    print(mage1.mage_information())
    print("--------------")
    mage1.add_item("Librariry")
    print(mage1.mage_information())
    print("--------------")
    mage1.remove_item("hand of justice")
    print(mage1.mage_information())
    print("--------------")
    mage1.heal(45)
    print(mage1.mage_information())
    print("--------------")
        
    add_mage(mages_list, mage1)

    list_all_mages(mages_list)
    print("--------------")
    add_mage(mages_list, mage2)

    list_all_mages(mages_list)
    print("--------------")
    print(find_mage_by_name(mages_list, "Veigar"))
    print("--------------")
    remove_mage(mages_list, mage1)

    list_all_mages(mages_list)
    print("--------------")
    
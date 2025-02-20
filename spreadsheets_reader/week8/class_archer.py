from class_character import Character

class Archer(Character):
    def __init__(self, name, health, attack_power, defense):
        Character.__init__(self,name,health,attack_power,defense)
        self.name = name
        self.health = health
        self.attack_power = attack_power
        self.defense = defense

    def abillity(self):
        self.attack_power += 14
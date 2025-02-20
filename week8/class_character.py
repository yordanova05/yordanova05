class Character():
    def __init__(self, name, health, attack_power, defense):
        self.name = name
        self.health = health
        self.attack_power = attack_power
        self.defense = defense

    def take_damage(self,amount):
        # self.health -= (amount - self.defense)
        damage = max(0, amount - self.defense)
        self.health -= damage

    def attack(self, target):
        target.take_damage(self.attack_power)

    def is_alive(self):
        return self.health > 0
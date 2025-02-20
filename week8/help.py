class Character:
    def __init__(self, name, health, attack_power, defense):
        self.name = name
        self.health = health
        self.attack_power = attack_power
        self.defense = defense

    def take_damage(self, amount):
        damage = max(0, amount - self.defense)
        self.health -= damage

    def attack(self, target):
        target.take_damage(self.attack_power)

    def is_alive(self):
        return self.health > 0


class Warrior(Character):
    def __init__(self, name, health, attack_power, defense):
        super().__init__(name, health, attack_power, defense)

    def abillity(self):
        self.attack_power += 15


class Mage(Character):
    def __init__(self, name, health, attack_power, defense):
        super().__init__(name, health, attack_power, defense)

    def abillity(self):
        self.attack_power *= 2


class Archer(Character):
    def __init__(self, name, health, attack_power, defense):
        super().__init__(name, health, attack_power, defense)

    def abillity(self):
        self.attack_power += 16


import random

warriors = ["Goblin", "Oni", "Alistar", "Aatrox", "GOD", "Irrelia", "Katarina"]
mages = ["Shadow", "Cassiopea", "Snake", "Veigar", "Witch", "Singed", "Lux"]
archers = ["Ashe", "Jhin", "Kaisa", "Robin", "Jinx", "Human", "Draven"]

print("Welcome to Battle of the YOSHI!")
character_name = input("Enter your character's name: ")
enemy_p = input("Choose your enemy (Warrior, Mage, Archer): ").split()
my_character = Character(character_name, 150, 31, 15)

try:
    if enemy_p[-1].title() == "Warrior":
        i = random.randint(0, len(warriors) - 1)
        name_enemy = warriors[i]
        enemy = Warrior(name_enemy, 150, 18, 12)
        print(f"\nA wild {name_enemy} appears!")

    elif enemy_p[-1].title() == "Mage":
        i = random.randint(0, len(mages) - 1)
        name_enemy = mages[i]
        enemy = Mage(name_enemy, 145, 15, 10)
        print(f"\nA poisoned {name_enemy} appears!")

    elif enemy_p[-1].title() == "Archer":
        i = random.randint(0, len(archers) - 1)
        name_enemy = archers[i]
        enemy = Archer(name_enemy, 135, 13, 11)
        print(f"\nA skilled {name_enemy} appears!")

    spell = 0
    while enemy.is_alive() and my_character.is_alive():
        char = input("\nDo you want to (A)ttack or (R)un? ")

        if char.upper() == "A":
            print(f"{character_name} attacks {name_enemy}!")
            enemy.take_damage(my_character.attack_power)
            print(f"{name_enemy} takes damage! Remaining health: {enemy.health}")
            if not enemy.is_alive():
                print(f"{character_name} wins!")
                break
        else:
            print(f"You lost from {name_enemy}!\nGame ends!")
            break

        print(f"\n{name_enemy} attacks back!")
        if enemy_p[-1].title() == "Warrior":
            if enemy.health < 75:
                enemy.abillity()
            my_character.take_damage(enemy.attack_power)

        elif enemy_p[-1].title() == "Mage":
            spell += 1
            if spell == 3:
                spell = 0
                enemy.abillity()
            my_character.take_damage(enemy.attack_power)

        elif enemy_p[-1].title() == "Archer":
            if random.choice([True, False]):
                enemy.abillity()
            my_character.take_damage(enemy.attack_power)

        print(f"{character_name} takes damage! Remaining health: {my_character.health}")

        if not my_character.is_alive():
            print(f"You lost against {name_enemy}!")
            break

except ValueError:
    print(f"Invalid enemy, {enemy_p[-1]} does not exist!")
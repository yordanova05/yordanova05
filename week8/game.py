import random
from class_character import Character
from class_warrior import Warrior
from class_mage import Mage
from class_archer import Archer
        

warriors = ["Goblin", "Oni" , "Alistar", "Aatrox", "GOD", "Irrelia", "Katarina"]
mages = ["Shadow", "Cassiopea", "Snake" , "Veigar", "Witch", "Singed", "Lux"]
archers = ["Ashe", "Jhin", "Kaisa", "Robin", "Jinx", "Human", "Draven"]

print("Welcome to Battle of the YOSHI!")
character_name = input("Enter your character's name: ")
enemy_p = input("Choose your enemy (Warrior, Mage, Archer): ").split()
my_character = Character(character_name, 150, 25, 15)

try:
    if enemy_p[-1].title() == "Warrior":
        i = random.randint(0,len(warriors)-1)
        name_enemy = warriors[i]
        enemy = Warrior(name_enemy, 150, 18, 12)
        print("\nA wild {0} appears!".format(name_enemy))

    elif enemy_p[-1].title() == "Mage":
        i = random.randint(0,len(mages)-1)
        name_enemy = mages[i]
        enemy = Mage(name_enemy, 145, 13,10)
        print("\nA poisoned {0} appears!".format(name_enemy))

    elif enemy_p[-1].title() == "Archer":
        i = random.randint(0,len(archers)-1)
        name_enemy = archers[i]
        enemy = Archer(name_enemy, 135, 11, 11)
        print("\nA poisoned {0} appears!".format(name_enemy))

    spell = 0
    crp = enemy.health/2
    while enemy.is_alive() and my_character.is_alive():
        char = input("\nDo you want to (A)ttack or (R)un? ")

        if char.upper() == "A":
            print(f"{character_name} attacks {name_enemy}!")
            enemy.take_damage(my_character.attack_power)
            print(f"{name_enemy} takes damage! Remaining health: {enemy.health}")
            if enemy.health <=0 : 
                print(f"{character_name} wins!") 
                break
        
        else: 
            print(f"You lost from {name_enemy}!\nGame ends!")
            break

        print(f"\n{name_enemy} attacks back!")
        if enemy_p[-1].title() == "Warrior":
            if enemy.health < crp:
                enemy.abillity()
            my_character.take_damage(enemy.attack_power)

        elif enemy_p[-1].title() == "Mage":
            spell += 1
            if spell==4 :
                spell = 0
                enemy.abillity()
            my_character.take_damage(enemy.attack_power)

        elif enemy_p[-1].title() == "Archer":
            r = random.randint(1,5)
            if r==2 :
                enemy.abillity()
            my_character.take_damage(enemy.attack_power)

        print(f"{character_name} takes damage! Remaining health: {my_character.health}")

        if my_character.health <=0 : 
                print(f"You lost against {name_enemy}!") 
                break

except ValueError:
    print(f"Invalid enemy,{enemy_p[-1]} not exist!")

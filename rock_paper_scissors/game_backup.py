import random
import time
    
def timer():
    timer_start = 3
    for i in range(timer_start, 0,-1):
        print(i)
        time.sleep(1)

def score(u_score, c_score):
    if u_score == 3:
        return "You win...lucky bastard!"
    elif c_score == 3:
        return "You lost, BONAKKKKKKKKKKk!"
    
def battle():
    computer_wins = 0
    your_wins = 0

    while computer_wins != 3 and your_wins != 3:

        random_comp = random.randint(0,2)
        if random_comp == 0:
            computer = "rock"
        elif random_comp == 1:
            computer = "paper"
        elif random_comp == 2:
            computer = "scissors"

        timer()
        your_object = input()

        if your_object == computer:
            print("AGAIN!")
        
        elif your_object.lower() == "rock":

            if computer == "scissors":
                your_wins+=1
                print(f"✂️ score: {your_wins}|{computer_wins}")
                print("----------")
                if your_wins == 3 or computer_wins == 3:
                    print(score(your_wins,computer_wins))

            elif computer == "paper":
                computer_wins+=1
                print(f"📃 score: {your_wins}|{computer_wins}")
                print("----------")
                if your_wins == 3 or computer_wins == 3:
                    print(score(your_wins,computer_wins))

        elif your_object.lower() == "paper":

            if computer == "scissors":
                computer_wins+=1
                print(f"✂️ score: {your_wins}|{computer_wins}")
                print("----------")
                if your_wins == 3 or computer_wins == 3:
                    print(score(your_wins,computer_wins))

            elif computer == "rock":
                your_wins+=1
                print(f"🪨 score: {your_wins}|{computer_wins}")
                print("----------")
                if your_wins == 3 or computer_wins == 3:
                    print(score(your_wins,computer_wins))

        elif your_object.lower() == "scissors":

            if computer == "paper":
                your_wins+=1
                print(f"📃 score: {your_wins}|{computer_wins}")
                print("----------")
                if your_wins == 3 or computer_wins == 3:
                    print(score(your_wins,computer_wins))

            elif computer == "rock":
                computer_wins+=1
                print(f"🪨 score: {your_wins}|{computer_wins}")
                print("----------")
                if your_wins == 3 or computer_wins == 3:
                    print(score(your_wins,computer_wins))


print("Welcome to Rock, Paper, Scissors!\nYou think you can beat me? I don't think so!\nLet's see what you got!")
print("On 1 write your answer!")

battle()

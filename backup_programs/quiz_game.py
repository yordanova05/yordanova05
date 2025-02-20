questions = (("What is the most popular cooking methods affect the nutritional value of food?"),
           ("How many bones are in the adult human body?"),
           ("What is the most popular game in the world?"),
           ("What country have the happiest people?"),
           ("What is the most popular foods around in Korea?"))
options = (("A. Smocking", "B. Frying","C. Steaming","D. Boiling"),
           ("A. 208", "B. 207 ","C. 206","D. 205"),
           ("A. Fortnite", "B. League of Legends","C. Minecraft","D. Genshin Impact"),
           ("A. Nordway", "B. France","C. Denmark","D. Italy"),
           ("A. Bibimbap", "B. Kimchi","C. Bulgogi","D. Tteokbokki"))
answers = ("B","C","B","C","B")

gueses = []
score = 0
question_num = 0

for question in questions:
    print("----------------------")
    print(question)
    for option in options[question_num]:
        print(option)
    guess = input("Type (A,B,C,D): ").upper()   
    gueses.append(guess)
    if guess == answers[question_num]:
        score+=1
        print("CORRECT!")
    else:
        print("INCORRECT!")
        print(f"The correct answer is {answers[question_num]}!")
    question_num+=1

print("-----------------")
print("     RESULTS     ")
print("-----------------")

print("Your answers: ",end="")
for guess in gueses:
    print(guess,end=", ")
print("\nThe answers: ",end="")
for answer in answers:
    print(answer,end=", ")
print("\n------------------")

score = int(score/len(questions)*100)
print(f"Your score is: {score}%")
# if score == 0 or score == 1 :
#     print("\nYour grade: Slab 2")
# elif score == 2:
#     print("\nYour grade: Sreden 3")
# elif score == 3:
#     print("\nYour grade: Dobur 4")
# elif score == 4:
#     print("\nYour grade: Mnogo dobur 5")
# elif score == 5:
#     print("\nYour grade: Otlichen 6")


#     while True:
#        guess = input("Type (A,B,C,D): ").upper()
#         if(answers[question_num] == guess):
#             print("CORRECT!")
#             gueses.append(guess)
#             score+=1
#             break
#         else:
#             print("INCORRECT,TRY AGAIN!")
#     question_num+=1
# print(score)
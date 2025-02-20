import random as rm
adjectives=[str(i) for i in (input("Input 3 adjectives(description): ").split())]
nouns=[str(i) for i in (input("Input 3 nouns(person,place,thing): ").split())]
verbs=[str(i) for i in (input("Input 3 verbs(-ing): ").split())]

print(f"Today i went to a {rm.choice(adjectives)} zoo")
print(f"In a exhibit i saw a {rm.choice(nouns)}")
print(f"{rm.choice(nouns)} was {rm.choice(adjectives)} and {rm.choice(verbs)}")
print(f"I was {rm.choice(adjectives)}")
print(adjectives)
import random 

def flip():
    number = random.random()
    if number >=.5:
        return True
    else:
        return False
    
def main(n):
    count_head=0
    count_tail=0
    string_of_flips=""
    for i in range(int(n)):
        if flip()==True:
            count_head+=1
            string_of_flips+="H"
        else:
            count_tail+=1
            string_of_flips+="T"
    print(f"Number of heads: {count_head}")
    print(f"Number of teails: {count_tail}")
    print(string_of_flips)

flips = input("please enter number of flips: ")
main(flips)
    


















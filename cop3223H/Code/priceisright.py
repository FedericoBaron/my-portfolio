# Federico Baron
# 9/3/2018
# The price is right

import random

#Assign a random price to my object.
itemPrice = random.randint(100, 1000)

#get the contestants guesses 
guess1 = int(input("Contestant #1, what is your guess for the price of this loveseat"))
guess2 = int(input("Contestant #2, what is your guess for the price of this loveseat"))

if guess1 > itemPrice and guess2 > itemPrice:
    print("Sorry no one wins both guessed too high")
elif guess1 > itemPrice:
    print("Contestant 2, you win because contestant 1 guessed too high")
elif guess2 > itemPrice:
    print("Contestant 1, you win because contestant 2 guessed too high")
elif guess1 > guess2:
    print("Contestant 1, you win because your guess is closest")
elif guess1 < guess2:
    print("Contestant 2, you win because your guess is closest")
else:
    print("You both tie, contestant #1 you get the washer. Contestant #2 you get the loveseat") 

print(itemPrice)

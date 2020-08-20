# Federico Baron
# 9/3/2018
# Using the random library to simulate a turn in Risk

import random

# Roll four dice
a_roll1 = random.randint(1,6)
a_roll2 = random.randint(1,6)
d_roll1 = random.randint(1,6)
d_roll2 = random.randint(1,6)

# Print out dice rolls.
print("The attacker rolled",a_roll1,"and",a_roll2)
print("The attacker rolled",d_roll1,"and",d_roll2)

# Put attackers in order.
if a_roll1 < a_roll2:
    tmp = a_roll1
    a_roll1 = a_roll2
    a_roll2 = tmp

# Put defenders in order.
if d_roll1 < d_roll2:
    tmp = d_roll1
    d_roll1 = d_roll2
    d_roll2 = tmp

# See when the attacker won by comparing corresponding dice.
score = 0
if a_roll1 > d_roll1:
    score += 1
if a_roll2 > d_roll2:
    score += 1

# Output result.
print("The attacker killed",score,"armies.")

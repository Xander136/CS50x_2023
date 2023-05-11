# make cash in python

from cs50 import get_float

# get number of coins owed
while True:
    coins_owed = get_float("Change owed: ")
    if coins_owed > 0:
        break

# convert to int
coins_owed = round(coins_owed * 100)

# set number of coins to 0
coins = 0

# get number of coins
while coins_owed > 0:
    # get number of quarters
    if coins_owed >= 25:
        coins_owed -= 25
        coins += 1
    # get number of dimes
    elif coins_owed >= 10:
        coins_owed -= 10
        coins += 1
    # get number of nickel
    elif coins_owed >= 5:
        coins_owed -= 5
        coins += 1
    # get number of pennies
    else:
        coins_owed -= 1
        coins += 1

# print number of coins
print(f"{coins}")
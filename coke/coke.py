# list of valid coins
COINS = ["25", "10", "5"]

# get user input
def get_change():
    change = ""
    while change not in COINS:
        change = input("Insert Coin: ")
    return int(change)

change = get_change()
print(change)
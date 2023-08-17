# list of valid coins
COINS = ["25", "10", "5"]

# get user input
def get_change():
    change = ""
    while change not in COINS:
        change = input("Insert Coin: ")
    return int(change)

def main():
    amount_due = 50
    coins = 0
    while amount_due > 0:
        print(f"Amount Due: {amount_due}")
        change = int(get_change())
        amount_due -= change
        coins += change


    if coins > 50:
        owed = coins - 50
        print(f"Change Owed: {owed}")
    else:
        print(f"Change Owed: 0")


main()
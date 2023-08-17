# list of valid coins
COINS = ["25", "10", "5"]

# get user input
def get_change(amount_due):
    change = ""
    while change not in COINS:
        print(f"Amount Due: {amount_due}")
        change = input("Insert Coin: ")
    return int(change)

def main():
    amount_due = 50
    coins = 0oo
    while amount_due > 0:
        change = int(get_change(amount_due))
        amount_due -= change
        coins += change


    if coins > 50:
        owed = coins - 50
        print(f"Change Owed: {owed}")
    else:
        print(f"Change Owed: 0")


main()
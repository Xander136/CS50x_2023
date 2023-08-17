# list of valid coins
COINS = ["25", "10", "5"]

# get user input
def get_change():
    change = ""
    while change not in COINS:
        change = input("Insert Coin: ")
    return int(change)

def main():
    amount = 50
    while payment < amount:
        print(f"Amount Due: {amount}")
        change = int(get_change())
        payment += change


main()
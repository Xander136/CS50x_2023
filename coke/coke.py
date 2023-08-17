# list of valid coins
COINS = ["25", "10", "5"]
AMOUNT = 50
# get user input
def get_change():
    change = ""
    while change not in COINS:
        change = input("Insert Coin: ")
    return int(change)

def main():
    while payment < AMOUNT:
        print(f"Amount Due: {AMOUNT}")
        change = int(get_change())
        payment -= change


main()
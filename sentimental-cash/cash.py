# create cash in python

def main():
    cents = get_cents()
    # Ask how many cents the customer is owed
    cents = get_cents()

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    printf("%i\n", coins)

def get_cents():
    # Prompt user for number of cents
    while True:
        try:
            cents = float(input("Change owed: "))
            if cents > 0:
                break

        except ValueError:
            print("Input how much change is owed.")

def calculate_quarters(cents):
    # divide cents by 25 to get number of quarters
    quarters = 0
    quarters = (cents / 25)
    return quarters

def calculate_dimes(cents):
    # divide cents by 10 to get number of quarters
    dimes = (cents / 10)
    return dimes

def calculate_nickels(cents):
    # divide cents by 5 to get number of nickels
    nickels = (cents / 5)
    return nickels


def calculate_pennies(cents):
    pennies = 0
    pennies = (cents / 1)
    return pennies

main()

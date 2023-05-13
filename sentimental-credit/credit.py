# credit using python

from cs50 import get_int
from cs50 import get_string

 # prompts the user for a credit card number

# check card numbers
# American Express uses 15-digit numbers, start with 34 or 37
# MasterCard uses 16-digit numbers, start with 51, 52, 53, 54, or 55
# Visa uses 13- and 16-digit, start with 4

# check sum
def check_sum(card_no):
    # Multiply every other digit by 2,
    product = []
    sum = 0
    total = 0
    card_no = list(card_no)
    card_no.reverse()
    for number in card_no[1::2]:
        number = int(number)
        product.append(number * 2)

    for number in product:
        total += number


    for number in card_no[0::2]:
        number = int(number)
        sum += number

    sum += total

    if sum % 10 == 0:
        return True
    else:
        return False

card_no = get_string("Number: ")
if check_sum(card_no):
    print("okay")
else:
    print("not okay")


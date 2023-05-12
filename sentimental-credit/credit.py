# credit using python

from cs50 import get_int
from cs50 import get_string

 # prompts the user for a credit card number

card_no = get_int("Number: ")

# check card numbers
# American Express uses 15-digit numbers, start with 34 or 37
# MasterCard uses 16-digit numbers, start with 51, 52, 53, 54, or 55
# Visa uses 13- and 16-digit, start with 4

# check sum
def check_sum(card_no):
    # Multiply every other digit by 2,
    for digit in range(card_no, )\
        total += sum(digit * 2)
    # starting with the number’s second-to-last digit,
    # and then add those products’ digits together.


    # if valid
    return true
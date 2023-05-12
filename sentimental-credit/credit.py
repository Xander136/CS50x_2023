# credit using python

from cs50 import get_int
from cs50 import get_string

 # prompts the user for a credit card number

card_no = get_int("Number: ")

# American Express uses 15-digit numbers, start with 34 or 37
# MasterCard uses 16-digit numbers, start with 51, 52, 53, 54, or 55
# Visa uses 13- and 16-digit, start with 4